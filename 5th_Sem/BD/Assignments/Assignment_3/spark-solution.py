#!usr/bin/env python3

import sys
import pyspark
import pyspark.sql.functions as f
from pyspark.sql import SparkSession

input_file = sys.argv[1]
output_folder = sys.argv[2]

sc = SparkSession.builder.master("local").getOrCreate()

df = sc.read.csv(input_file, header=True, inferSchema=True)
cleaned_df = df.na.drop().dropDuplicates(['Ticket number'])
average_fine_by_state = cleaned_df.groupBy('RP State Plate').agg(f.avg('Fine amount').alias('Avg fine'))

joined_df = cleaned_df.join(average_fine_by_state, on='RP State Plate')
ans_df = joined_df.filter(joined_df['Color'] == "WH").filter(joined_df['Fine amount'] > joined_df['Avg fine']).orderBy('Ticket number').select('Ticket number')

ans_df.write.csv(output_folder)

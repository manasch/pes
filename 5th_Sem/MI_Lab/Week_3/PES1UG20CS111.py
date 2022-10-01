'''
Assume df is a pandas dataframe object of the dataset given
'''

import numpy as np
import pandas as pd
import random
import math


'''Calculate the entropy of the enitre dataset'''
# input:pandas_dataframe
# output:int/float
def get_entropy_of_dataset(df):
    # TODO
    target = df.columns[-1]
    target_freq = df[target].value_counts()
    total = len(df)
    entropy = 0

    for outcome, freq in target_freq.items():
        ratio = freq / total
        entropy += (-ratio * math.log2(ratio))
    
    return entropy


'''Return avg_info of the attribute provided as parameter'''
# input:pandas_dataframe,str   {i.e the column name ,ex: Temperature in the Play tennis dataset}
# output:int/float
def get_avg_info_of_attribute(df, attribute):
    # TODO
    attribute_values = df[attribute].value_counts()
    avg_info = 0
    total = len(df)

    # Using the previous function to calculate the entropy for each value in that attribute
    # by passing a new database with just those values
    for value, freq in attribute_values.items():
        temp = df[df[attribute] == value]
        res = get_entropy_of_dataset(temp)
        avg_info += (freq / total) * res

    return avg_info


'''Return Information Gain of the attribute provided as parameter'''
# input:pandas_dataframe,str
# output:int/float
def get_information_gain(df, attribute):
    # TODO
    entropy = get_entropy_of_dataset(df)
    attr_information = get_avg_info_of_attribute(df, attribute)
    information_gain = entropy - attr_information
    return information_gain




#input: pandas_dataframe
#output: ({dict},'str')
def get_selected_attribute(df):
    '''
    Return a tuple with the first element as a dictionary which has IG of all columns 
    and the second element as a string with the name of the column selected

    example : ({'A':0.123,'B':0.768,'C':1.23} , 'C')
    '''
    # TODO
    entropy_table = {}
    for attribute in df.columns[:-1]:
        attr_info_gain = get_information_gain(df, attribute)
        entropy_table[attribute] = attr_info_gain
    
    return (entropy_table, max(entropy_table, key=entropy_table.get))

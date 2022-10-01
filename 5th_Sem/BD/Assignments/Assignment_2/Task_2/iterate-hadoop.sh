#!/bin/sh
CONVERGE=1
ITER=1
rm w w1 log*

$HADOOP_HOME/bin/hadoop dfsadmin -safemode leave
hdfs dfs -rm -r /task-* 

$HADOOP_HOME/bin/hadoop jar $HADOOP_HOME/share/hadoop/tools/lib/hadoop-*streaming*.jar \
-mapper "'/home/pes1ug20cs111/UE20CS322-A2/Task_1/mapper.py'" \
-reducer "'/home/pes1ug20cs111/UE20CS322-A2/Task_1/reducer.py' '/home/pes1ug20cs111/UE20CS322-A2/Task_2/w'"  \
-input "/a2/web-Google.txt" \
-output "/a2/t2-output1"


while [ "$CONVERGE" -ne 0 ]
do
	echo "############################# ITERATION $ITER #############################"
	$HADOOP_HOME/bin/hadoop jar $HADOOP_HOME/share/hadoop/tools/lib/hadoop-*streaming*.jar \
	-mapper "'/home/pes1ug20cs111/UE20CS322-A2/Task_2/mapper.py' '/home/pes1ug20cs111/UE20CS322-A2/Task_2/w' '/home/pes1ug20cs111/UE20CS322-A2/Task_2/page_embeddings.json'" \
	-reducer "'/home/pes1ug20cs111/UE20CS322-A2/Task_2/reducer.py'" \
	-input "/a2/t2-output1/part-00000" \
	-output "/a2/t2-output2"
	touch w1
	hadoop dfs -cat "/a2/t2-output2/part-00000" > "/home/pes1ug20cs111/UE20CS322-A2/Task_2/w1"
	CONVERGE=$(python3 /home/pes1ug20cs111/UE20CS322-A2/Task_2/check_conv.py $ITER>&1)
	ITER=$((ITER+1))
	hdfs dfs -rm -r "/a2/t2-output2"
	echo $CONVERGE
done

- Go to home directory and run the following to start all hadoop instances

```bash
cd
cd hadoop-3.3.3/sbin/
./start-all.sh
```

- Run jps to confirm that 6 java processes are running

```bash
jps
```

- Create a new subdirectory for the assignment, and transfer the dataset

```bash
hdfs dfs -mkdir /a1
hdfs dfs -put Air_Quality_201X.json /a1
```

- Find the mapper.py and reducer.py codes above and place them in the home directory. Run the following for each test case and match the output to the respective cases

```bash
hadoop jar $HADOOP_HOME/share/hadoop/tools/lib/hadoop-streaming-3.3.3.jar -input /a1/Air_Quality_2017.json -output /a1/output/ -mapper "$PWD/mapper1.py" -reducer "$PWD/reducer.py"

hadoop jar $HADOOP_HOME/share/hadoop/tools/lib/hadoop-streaming-3.3.3.jar -input /a1/Air_Quality_2018.json -output /a1/output2/ -mapper "$PWD/mapper1.py" -reducer "$PWD/reducer.py"

hadoop jar $HADOOP_HOME/share/hadoop/tools/lib/hadoop-streaming-3.3.3.jar -input /a1/Air_Quality_2017.json -output /a1/output3/ -mapper "$PWD/mapper2.py 20 40 25" -reducer "$PWD/reducer.py"

hadoop jar $HADOOP_HOME/share/hadoop/tools/lib/hadoop-streaming-3.3.3.jar -input /a1/Air_Quality_2018.json -output /a1/output4/ -mapper "$PWD/mapper2.py 20 40 25" -reducer "$PWD/reducer.py"
```

- To view the output file, do the following

```bash
hdfs dfs -cat /a1/output/part-00000
hdfs dfs -cat /a1/output2/part-00000
hdfs dfs -cat /a1/output3/part-00000
hdfs dfs -cat /a1/output4/part-00000
```

- Stop all the java processes at the end

```bash
cd
cd hadoop-3.3.3/sbin
./stop-all.sh
```
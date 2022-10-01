- Start the hadoop instance by running this from anywhere.
- Ensure that 6 java processes are running.

```bash
start-all.sh
jps
```

- Create the directories for the task, and copy the require datasets.

```bash
hdfs dfs -mkdir /a2
hdfs dfs -put ./web-BerkStan.txt /a2
hdfs dfs -put ./web-Google.txt /a2
````

- For task 1, run the following in the task 1 folder.

```bash
hadoop jar $HADOOP_HOME/share/hadoop/tools/lib/hadoop-streaming-3.3.3.jar \
-mapper "$PWD/mapper.py" \
-reducer "'$PWD/reducer.py' '$PWD/w'" \
-input "/a2/web-BerkStan.txt" \
-output "/a2/t1-output/"
```

- For task 2, run the `iterate-hadoop.sh` script in the task 2 folder.

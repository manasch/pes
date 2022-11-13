- Install spark and kafka using the scripts provided

```bash
source spark.sh
source kafka.sh
```

- Spark Task
	- Run the `spark-solution.py` with the given dataset and path to output folder as parameters.
	```bash
	python3 spark-solution.py path/to/spark-5-percent-dataset.csv path/to/output
	````
	- Change the sparksession's master URL to `'yarn'` for submission.

- Kafka Task
	- Start zookeeper and kafka
	```bash 
	sudo systemctl start zookeeper kafka
	```
	- Run consumer and producer commands in seperate terminals
	```bash
	python3 kakfa-consumer.py "topic_name" > output.json
	cat path/to/kafka-5-percent-dataset.csv | python3 kakfa-producer.py "topic_name"

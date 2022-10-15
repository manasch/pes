CREATE OR REPLACE TABLE t1 ( a INT );
CREATE OR REPLACE TABLE t2 ( b INT );
CREATE OR REPLACE TABLE student_tests (
 name CHAR(10), test CHAR(10), 
 score TINYINT, test_date DATE
);
INSERT INTO t1 VALUES (1), (2), (3);
INSERT INTO t2 VALUES (2), (4);

INSERT INTO student_tests 
 (name, test, score, test_date) VALUES
 ('Chun', 'SQL', 75, '2012-11-05'), 
 ('Chun', 'Tuning', 73, '2013-06-14'),
 ('Esben', 'SQL', 43, '2014-02-11'), 
 ('Esben', 'Tuning', 31, '2014-02-09'), 
 ('Kaolin', 'SQL', 56, '2014-01-01'),
 ('Kaolin', 'Tuning', 88, '2013-12-29'), 
 ('Tatiana', 'SQL', 87, '2012-04-28'), 
 ('Tatiana', 'Tuning', 83, '2013-09-30');

CREATE OR REPLACE TABLE student_details (
 id INT NOT NULL AUTO_INCREMENT, name CHAR(10), 
 date_of_birth DATE, PRIMARY KEY (id)
);
INSERT INTO student_details (name,date_of_birth) VALUES 
 ('Chun', '1993-12-31'), 
 ('Esben','1946-01-01'),
 ('Kaolin','1996-07-16'),
 ('Tatiana', '1988-04-13');

SELECT * FROM student_details;

--Join

SELECT * FROM t1 INNER JOIN t2 ON t1.a = t2.b;

--Aggregate

SELECT MAX(a) FROM t1;
SELECT MIN(a) FROM t1;
SELECT AVG(a) FROM t1;

--Group by

SELECT name, MAX(score) FROM student_tests GROUP BY name;

--Order by
SELECT name, test, score FROM student_tests ORDER BY score DESC;

--Nested query
SELECT name,test, score FROM student_tests WHERE score=(SELECT MIN(score) FROM student_tests);
SELECT name, test, score FROM student_tests st1 WHERE score = (
  SELECT MAX(score) FROM student_tests st2 WHERE st1.name = st2.name
); 

--calculate age

SELECT CURDATE() AS today;
SELECT name, date_of_birth, TIMESTAMPDIFF(YEAR,date_of_birth,'2014-08-02') AS age 
  FROM student_details;

--using user defined variables
SELECT @avg_score:= AVG(score) FROM student_tests;
SELECT * FROM student_tests WHERE score > @avg_score;
SET @count = 0;
SELECT @count := @count + 1 AS counter, name, date_of_birth FROM student_details;

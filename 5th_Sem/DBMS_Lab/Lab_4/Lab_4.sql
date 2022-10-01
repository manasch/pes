-- The load commands are not resulting in the required solution.
-- Insert from rail.csv for all tables except for the table that is a foreign key and has no constraints.

-- Task 1

-- 1)

LOAD DATA INFILE 'D:/pes/5th_Sem/DBMS_Lab/Lab_4/dataset/train.csv' INTO TABLE train
COLUMNS TERMINATED BY ','
OPTIONALLY ENCLOSED BY '"'
ESCAPED BY '"'
LINES TERMINATED BY '\n'
IGNORE 1 LINES;

LOAD DATA INFILE 'D:/pes/5th_Sem/DBMS_Lab/Lab_4/dataset/compartment.csv' INTO TABLE compartment
COLUMNS TERMINATED BY ','
OPTIONALLY ENCLOSED BY '"'
ESCAPED BY '"'
LINES TERMINATED BY '\n'
IGNORE 1 LINES;

LOAD DATA INFILE 'D:/pes/5th_Sem/DBMS_Lab/Lab_4/dataset/fare_table.csv' INTO TABLE fare
COLUMNS TERMINATED BY ','
OPTIONALLY ENCLOSED BY '"'
ESCAPED BY '"'
LINES TERMINATED BY '\n'
IGNORE 1 LINES;

LOAD DATA INFILE 'D:/pes/5th_Sem/DBMS_Lab/Lab_4/dataset/payment_info.csv' INTO TABLE payment_info
COLUMNS TERMINATED BY ','
OPTIONALLY ENCLOSED BY '"'
ESCAPED BY '"'
LINES TERMINATED BY '\n'
IGNORE 1 LINES;

LOAD DATA INFILE 'D:/pes/5th_Sem/DBMS_Lab/Lab_4/dataset/route_info.csv' INTO TABLE route_info
COLUMNS TERMINATED BY ','
OPTIONALLY ENCLOSED BY '"'
ESCAPED BY '"'
LINES TERMINATED BY '\n'
IGNORE 1 LINES;

LOAD DATA INFILE 'D:/pes/5th_Sem/DBMS_Lab/Lab_4/dataset/ticket.csv' INTO TABLE ticket
COLUMNS TERMINATED BY ','
OPTIONALLY ENCLOSED BY '"'
ESCAPED BY '"'
LINES TERMINATED BY '\n'
IGNORE 1 LINES;

LOAD DATA INFILE 'D:/pes/5th_Sem/DBMS_Lab/Lab_4/dataset/ticket_passenger.csv' INTO TABLE ticket_passenger
COLUMNS TERMINATED BY ','
OPTIONALLY ENCLOSED BY '"'
ESCAPED BY '"'
LINES TERMINATED BY '\n'
IGNORE 1 LINES;

LOAD DATA INFILE 'D:/pes/5th_Sem/DBMS_Lab/Lab_4/dataset/train_user.csv' INTO TABLE train_user
COLUMNS TERMINATED BY ','
OPTIONALLY ENCLOSED BY '"'
ESCAPED BY '"'
LINES TERMINATED BY '\n'
IGNORE 1 LINES;

LOAD DATA INFILE 'D:/pes/5th_Sem/DBMS_Lab/Lab_4/dataset/user_phone.csv' INTO TABLE user_phone
COLUMNS TERMINATED BY ','
OPTIONALLY ENCLOSED BY '"'
ESCAPED BY '"'
LINES TERMINATED BY '\n'
IGNORE 1 LINES;

LOAD DATA INFILE 'D:/pes/5th_Sem/DBMS_Lab/Lab_4/dataset/user_train.csv' INTO TABLE user_train
COLUMNS TERMINATED BY ','
OPTIONALLY ENCLOSED BY '"'
ESCAPED BY '"'
LINES TERMINATED BY '\n'
IGNORE 1 LINES;

-- 2)

UPDATE train_user SET age=DATE_FORMAT(FROM_DAYS(DATEDIFF(NOW(), dob)), '%Y') + 0;

-- 3)

SELECT * FROM route_info WHERE distance >= 70 and distance <= 150;

-- 4)

SELECT * FROM route_info WHERE (from_station_name="Chennai" and to_station_name="Sholingur") or (from_station_name="Sholingur" and to_station_name="Chennai");

-- 5)

SELECT * FROM train WHERE train_type != "Mail";

-- 6)

SELECT train_name FROM train WHERE source="Bengaluru" and destination="Chennai";

-- 7)

SELECT train_no, train_name, departure, departure_time FROM train NATURAL JOIN ticket WHERE departure="Chennai" and departure_time > "8:00:00";

-- 8)

SELECT user_id, firstname, lastname, dob FROM train_user WHERE dob >= "1980-01-01" and dob < "1990-01-01";

-- 9)

SELECT user_id, firstname FROM train_user WHERE left(firstname, 1) = 'S';

-- 10)

SELECT train_number, compartment_type, availability FROM compartment WHERE compartment_type="I Class" and train_number=62621;

-- 11)

SELECT pnr, transaction_no FROM payment_info WHERE bank="UNION BANK";

-- Task 2

-- 1) Creating a user and granting permissions

CREATE USER manas@localhost identified by '12321';
GRANT UPDATE, DELETE on table compartment to manas@localhost;
system mysql -u manas -p
SELECT * FROM compartment;
GRANT INSERT, SELECT on table compartment to manas@localhost;

-- 2)

GRANT UPDATE, DELETE, INSERT, SELECT on table train to main@localhost;
system mysql -u manas -p
INSERT INTO train VALUES(12321, 'India Travels', 'Superfast', 'Kanyakumari', 'Jammu', 'yes');
SELECT * FROM train WHERE train_no=12321;
show grants for manas@localhost;
SELECT user();
revoke UPDATE, DELETE on train FROM manas@localhost;
INSERT INTO train VALUES(12521, 'West Travels', 'Superfast', 'Bombay', 'Kerala', 'yes');
UPDATE train SET train_type='Mail' WHERE train_no=12521;
DELETE FROM train WHERE train_no=12521;

-- 3)

START TRANSACTION;
SELECT * FROM train;
SAVEPOINT l41;
INSERT INTO train VALUES(55555, 'Karnataka Express', 'Mail', 'Bidar', 'yes');
SAVEPOINT l42;
SELECT * FROM train;
UPDATE train SET source='Mandya' WHERE train_no=55555;
SELECT * FROM train;
ROLLBACK to SAVEPOINT l42;
SELECT * FROM train;
COMMIT;

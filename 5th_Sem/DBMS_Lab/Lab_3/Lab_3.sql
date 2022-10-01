-- Railway Reservation System
-- Database description

create database pes1ug20cs111_manas;

use pes1ug20cs111_manas;

create table train(
	train_no int primary key,
	name varchar(50),
	source varchar(50),
	destination varchar(50),
	availability int,
	train_type varchar(15),
	check(
		train_type="Superfast" or
		train_type="Fast" or
		train_type="Mail"));

create table compartment(
	type int,
	compartment_no int primary key,
	capacity int,
	availability boolean,
	train_no int,
	foreign key (train_no) references train(train_no),
	check(
		(type=1 and capacity=16) or
		(type=2 and capacity=30) or
		(type=3 and capacity=60) and
		compartment_no >= 1 and compartment_no <= 5));

create table route_info(
	from_station_no int,
	from_station_name varchar(50),
	to_station_no int,
	to_station_name varchar(50),
	distance int,
	train_no int,
	primary key (from_station_no, to_station_no),
	foreign key (train_no) references train(train_no));

create table user(
	user_id char(10) primary key,
	user_type varchar(10),
	fname varchar(50),
	lname varchar(50),
	age int,
	DOB datetime,
	pincode int,
	street_no int,
	check(
		user_type="admin" or
		user_type="passenger"));

create table user_train(
	train_no int,
	user_id char(10),
	date_time_stamp datetime primary key,
	foreign key (train_no) references train(train_no),
	foreign key (user_id) references user(user_id));

create table user_phone(
	user_id char(10),
	phone_no int primary key,
	foreign key (user_id) references user(user_id));

create table ticket(
	PNR char(20) primary key,
	train_number int,
	travel_date date,
	departure varchar(50),
	arrival varchar(50),
	departure_time time,
	arrival_time time,
	user_id char(10),
	train_type varchar(15),
	compartment_type int,
	compartment_no int,
	foreign key (user_id) references user(user_id));

create table ticket_passenger(
	seat_no char(5) primary key,
	name varchar(50),
	age int,
	PNR char(20),
	foreign key (PNR) references ticket(PNR));

create table payment_info(
	transaction_id char(20) primary key,
	bank varchar(20),
	card_number int,
	price float,
	PNR char(20),
	foreign key (PNR) references ticket(PNR));

create table faretable(
	train_type varchar(15),
	compartment_type int,
	fare_per_km decimal,
	primary key (train_type, compartment_type));

alter table train modify name varchar(15) not null, modify train_type varchar(15) not null;

alter table compartment alter availability set default true;

alter table train add unique (name);

alter table ticket_passenger add check(age > 5);

rename table faretable to fare_table;

truncate table fare_table;

drop table fare_table;
```
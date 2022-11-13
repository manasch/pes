-- Lab - 6: Aggregate Function
-- Load the SQL database from Lab-4's rail.sql

-- 1 Find the average distance between subsequent stations for every train

select train_no, avg(distance)
from route_info
group by train_no;

-- 2 Find the average distance between subsequent stations for every train and display them in descending order

select train_no, avg(distance)
from route_info
group by train_no
order by avg(distance) desc;

-- 3 Display the list of train numbers and the distance travelled by each in descending order of the distance travelled

select train_no, sum(distance)
from route_info
group by train_no
order by sum(distance) desc;

-- 4 List those trains that have maximum and minimum number compartments and also display number of compartments they have. (2 queries one to find max and other to find min)

select train_number, count(*) as 'Count_Comp'
from compartment
group by train_number
order by count(*) desc limit 1;

select train_number, count(*) as 'Count_Comp'
from compartment
group by train_number
order by count(*) limit 2;

-- Alternative

with comp (train_no, comp_count) as (
	select train_number, count(*)
	from compartment
	group by train_number
	order by count(*) desc
)
select train_no, comp_count
from comp
where comp_count in (
	select max(comp_count)
	from comp
);

-- 5 Display the number of phone numbers corresponding to the user_id(s) ADM_001, USR_006, USR_10

select user_id, count(*)
from user_phone
where user_id in ('ADM_001', 'USR_006', 'USR_010')
group by user_id;

-- 6 Find the average fare per km for each train type specified and display the train type and corresponding average fare per km as 'Avg_Fare' in decreasing order of Avg_Fare

select train_type, avg(fare_per_km) as 'Avg_Fare'
from fare
group by train_type
order by Avg_Fare desc;

-- 7 Retrieve all details of the oldest passenger.

select * from ticket_passenger
order by age desc limit 1;

-- 8 Count the number of passengers whose name consists of 'Ullal'

select count(*) as 'Ullal Count'
from ticket_passenger
where name like '%Ullal%';

-- Lab - 7: Union, Intersection and Minus Operators
-- Load the SQL database from Lab-4's rail.sql

-- 0

insert into ticket (PNR, train_no, travel_date, passenger_id, arrival_time, departure_time, train_type, compartment_type, compartment_no, arrival, departure)
values ('PNR021', 62621, '2021-10-22', 'USR_008', '20:30:00', '16:00:00', 'Superfast', 'I Class', 'F01', 'Chennai', 'Bengaluru');

update train
set source = trim(source), destination = trim(destination);

-- 1 Find the list of passengers (user_id, user_type First name and last name) who have traveled from Bengaluru to Chennai durin the month of Oct 2021 and Aug 2022.

select u.user_id, u.user_type, u.firstname, u.lastname
from train_user as u inner join ticket as t on u.user_id = t.passenger_id
where t.departure = "Bengaluru" and t.arrival = "Chennai" and t.travel_date between "2021-10-01" and "2021-10-31"
union
select u.user_id, u.user_type, u.firstname, u.lastname
from train_user as u inner join ticket as t on u.user_id = t.passenger_id
where t.departure = "Bengaluru" and t.arrival = "Chennai" and t.travel_date between "2022-08-01" and "2022-08-31";

-- Can also do {t.travel_date like "2021-10-%"}

-- 2 Find the list of passengers (user_id, user_type First name and last name) who have traveled from Bengaluru to Chennai during the month of Oct 2021 and also during Aug 2022.

select u.user_id, u.user_type, u.firstname, u.lastname
from train_user as u inner join ticket as t on u.user_id = t.passenger_id
where t.departure = "Bengaluru" and t.arrival = "Chennai" and t.travel_date between "2021-10-01" and "2021-10-31"
intersect
select u.user_id, u.user_type, u.firstname, u.lastname
from train_user as u inner join ticket as t on u.user_id = t.passenger_id
where t.departure = "Bengaluru" and t.arrival = "Chennai" and t.travel_date between "2022-08-01" and "2022-08-31";

-- 3  Find the list of passengers (user_id, user_type First name and last name) who have traveled from Bengaluru to Chennai during the month of Aug 2022 and not in Oct 2021.

select u.user_id, u.user_type, u.firstname, u.lastname
from train_user as u inner join ticket as t on u.user_id = t.passenger_id
where t.departure = "Bengaluru" and t.arrival = "Chennai" and t.travel_date between "2022-08-01" and "2022-08-31"
intersect
select u.user_id, u.user_type, u.firstname, u.lastname
from train_user as u inner join ticket as t on u.user_id = t.passenger_id
where t.departure = "Bengaluru" and t.arrival = "Chennai" and t.travel_date not between "2021-10-01" and "2021-10-31";

-- 4 Find the list of passengers (user_id, user_type, First name and last name) who have traveled from Bengaluru to Chennai and returned to Bengaluru within a week.

select u1.user_id, u1.user_type, u1.firstname, u1.lastname
from train_user as u1 join ticket as t1 on u1.user_id = t1.passenger_id
where t1.departure = "Bengaluru" and t1.arrival = "Chennai"
and exists (
	select u2.user_id, u2.user_type, u2.firstname, u2.lastname
	from train_user as u2 join ticket as t2 on u2.user_id = t2.passenger_id
	where t2.departure = "Chennai" and t2.arrival = "Bengaluru" and u1.user_id = u2.user_id and t1.travel_date - t2.travel_date <= 7
);

-- 5  Find the list of passengers (user_id, user_type, First name and last name) who have traveled from Bengaluru to Chennai and did not return to Bengaluru (in other words, only one way travel from Bengaluru to Chennai)

select u1.user_id, u1.user_type, u1.firstname, u1.lastname
from train_user as u1 join ticket as t1 on u1.user_id = t1.passenger_id
where t1.departure = "Bengaluru" and t1.arrival = "Chennai"
except
select u2.user_id, u2.user_type, u2.firstname, u2.lastname
from train_user as u2 join ticket as t2 on u2.user_id = t2.passenger_id
where t2.departure = "Chennai" and t2.arrival = "Bengaluru";

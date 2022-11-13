-- Lab - 5: SQL Joins: Inner, Outer; Sub Queries: Correlated and Uncorrelated
-- Load the SQL database from Lab-4's rail.sql

-- 1) Update price of the ticket

-- a) Create a view compute_price as below

create view compute_price as
select ticket.pnr, ticket.train_no, ticket.departure, ticket.arrival, route_info.distance, fare.fare_per_km
from ticket, route_info, fare
where (ticket.train_no = route_info.train_no and
	ticket.departure = route_info.from_station_name and
	ticket.arrival = route_info.to_station_name and
	fare.train_type = ticket.train_type and
	fare.compartment_type = ticket.compartment_type);

-- b) Create a View passenger_num

create view passenger_num as select PNR, count(PNR) as numbers
from ticket_passenger group by PNR;

-- c) Update Payment_info.price as below

update payment_info as p inner join compute_price as cs
on p.PNR = cs.PNR inner join passenger_num as pn
on cs.PNR = pn.PNR
set p.price = cs.distance * cs.fare_per_km * pn.numbers;

-- 2) Retrieve the all stations along route of the Trains along with the distance between the stations for all the users

select t.train_no, t.train_name, t.source, t.destination, r.distance
from train as t natural join route_info as r
where t.source = r.from_station_name and t.destination = r.to_station_name;

-- 3) Retrieve the Train no of train which is leaving Bengaluru and arriving at Chennai with compartments availability greater than 10

select t.train_no
from train as t join compartment as c
on t.train_no = c.train_number
where t.source = "Bengaluru" and t.destination = "Chennai" and c.availability > 10;

-- 4) Retrieve first and last name of users who have booked a ticket with price greater than 500

select tu.firstname, tu.lastname
from train_user as tu join ticket as t
on tu.user_id = t.passenger_id join payment_info as p
on t.pnr = p.pnr
where p.price > 500;

-- 5) Retrieve the first name, last name, DOB and ticket PNR if they’ve bought it for all users.

select tu.firstname, tu.lastname, tu.dob, t.pnr
from train_user as tu left outer join ticket as t
on tu.user_id = t.passenger_id
where t.pnr is not null;

-- 6) Retrieve the first name, last name,of the Users who have not bought a ticket.

select tu.firstname, tu.lastname
from train_user as tu left outer join ticket as t
on tu.user_id = t.passenger_id
where t.pnr is null;

-- 7) Retrieve the ticket PNR, Train number, travel date and along with all users first name and last name.

select t.pnr, t.train_no, t.travel_date, tu.firstname, tu.lastname
from ticket as t right outer join train_user as tu
on tu.user_id = t.passenger_id;

-- Alternative
-- select t.pnr, t.train_no, t.travel_date, tu.firstname, tu.lastname
-- from train_user as tu right outer join ticket as t
-- on tu.user_id = t.passenger_id;

-- 8) Retrieve the user id if they've traveled in a train along with train id and name of all trains.

select ut.user_id, ut.train_id, tr.train_name
from user_train as ut right outer join train as tr
on ut.train_id = tr.train_no;

-- 9) Retrieve the train no and name of trains whose destination is not Mangaluru and distance is not less than 100km and departure time is not 8:30:00 PM. (Correlated)

select train_no, train_name
from train
where train.destination != "Mangaluru" and
not exists (
	select * from route_info
	where route_info.train_no = train.train_no and
	route_info.from_station_name = train.source and
	route_info.to_station_name = train.destination and
	route_info.distance < 100 and
	not exists (
		select * from ticket
		where ticket.train_no = train.train_no and
		ticket.departure_time <> "20:30:00"
		)
);

-- 10) Retrieve the User ID who has spent more than the average ticket price. (Uncorrelated)

select passenger_id from ticket natural join payment_info
where price > (select avg(price) from payment_info);

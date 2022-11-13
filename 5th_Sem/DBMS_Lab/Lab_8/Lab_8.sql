-- Lab - 8: Creating Functions and Stored Procedures
-- Load the SQL database from Lab-4's rail.sql

-- 1 Write a function to find the number of tickets booked by a customer. If no of tickets is more than 3 for the current month then display error message as “cannot purchase tickets current limit is over”.

DELIMITER $$

create function ticket_eligible(uid varchar(20))
returns varchar(50)
deterministic
begin
    declare msg varchar(50);
    declare ticket_limit int;
    declare ticket_count int;
    set ticket_limit = 3;

    set ticket_count = (select count(*) from ticket where month(ticket.travel_date) = 8 and ticket.passenger_id = uid group by passenger_id);

    if ticket_count > ticket_limit then
        set msg = "Cannot purchase tickets, current limit is over.";
    else
        set msg = "Can purchase tickets.";
    end if;
    
    return msg;
end; $$

DELIMITER ;


-- Hardcoding 8 as all travel dates are in August

select passenger_id, count(*) as "tickets_booked", ticket_eligible(passenger_id)
from ticket
where month(travel_date) = 8
group by passenger_id;

-- 2 Write a stored procedure to calculate the age of the customer when the date of birth is given. Update the column named age in the customer table.

DELIMITER $$

create procedure calc_dob(in pid varchar(10), in date_of_birth date, out curr_age int)
begin
set curr_age = date_format(from_days(datediff(curdate(), date_of_birth)), '%Y') + 0;
update train_user
set train_user.age = curr_age
where train_user.user_id = pid;
end; $$

DELIMITER ;

set @p0 = 'USR_002';
set @p1 = (select dob from train_user where train_user.user_id = @p0);
set @p2 = 0;

select * from train_user where train_user.user_id = @p0;

call calc_dob(@p0, @p1, @p2);
select @p2 as 'age';

select * from train_user where train_user.user_id = @p0;

-- Lab - 9: Creating Triggers
-- Load the SQL database from Lab-4's rail.sql

-- 1 Write a trigger on insert to compartment table when a new compartment gets added to a train and make sure that total number of compartments available in the train does not exceed more than 4

DELIMITER $$
create trigger compartment_check
before insert
on compartment for each row
begin
    declare msg varchar(255);
    declare cnt int;
    set msg = "Compartments cannot exceed 4";
    if (select count(*) from compartment where train_number = new.train_number) >= 4 then
        signal sqlstate '45000'
        set message_text = msg;
    end if;
end $$
DELIMITER ;

-- Valid
insert into compartment values ('G01', 'III Class', 60, 10, 25260);

-- Invalid
insert into compartment values ('F02', 'I Class', 16, 5, 58450);

-- 2 Create a trigger to update the pnr number in payment info to null whenever a record is deleted in ticket table.

DELIMITER $$
create trigger ticket_delete_backup
before delete
on ticket for each row
begin
    insert into payment_backup (select * from payment_info where pnr = old.pnr);
    delete from payment_info where pnr = old.pnr;
    delete from ticket_passenger where pnr = old.pnr;
end $$
DELIMITER ;

create table payment_backup like payment_info;

delete from ticket where pnr = 'PNR005';
select * from payment_backup;


-- 1 Retrieve the names of all courses taught by the Professors during the period 2001 - 2004

select Year, Instructor, CourseName from section natural join course where Year between 2001 and 2004;

-- 2 We need to maintain report of the student as follows:
-- 		Student_Report(StudentNumber, CourseNumber,marks)
-- Populate this table with each student's number with all the courses he/she has registered. Populate the marks of each student for the courses they have enrolled in multiples of 10 with maximum of 100 marks. (without using insert statements)

create table if not exists Student_Report(
	StudentNumber int not null,
	CourseNumber varchar(8) not null,
	marks int,
	primary key (StudentNumber, CourseNumber),
	foreign key (StudentNumber) references STUDENT(StudentNumber) on delete cascade,
	foreign key (CourseNumber) references COURSE(CourseNumber) on delete cascade
) as 
select StudentNumber, CourseNumber, (FLOOR(RAND() * 11))*10 as 'Marks'
from STUDENT
join SECTION on STUDENT.Class =  SECTION.SectionIdentifier;

-- 3 For such schema, create a trigger so that the total and average of specified marks is automatically inserted whenever a record is insert into Student_Report.
-- Creating a new table

create table if not exists Student_Report_Avg(
	StudentNumber int not null,
	CourseNumber varchar(8) not null,
	marks int,
	average float,
	total int,
	primary key (StudentNumber, CourseNumber),
	foreign key (StudentNumber) references STUDENT(StudentNumber) on delete cascade,
	foreign key (CourseNumber) references COURSE(CourseNumber) on delete cascade
)

delimiter $$
create trigger student_avg
before insert
on Student_Report for each row
begin
	declare total int;
	declare average float;

	set average = (select avg(Marks) from Student_Report);
	set total = (select sum(Marks) from Student_Report);
	insert into Student_Report_Avg values (new.StudentNumber, new.CourseNumber, average, total);
end $$
delimiter ;

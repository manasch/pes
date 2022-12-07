CREATE TABLE STUDENT (
Name varchar(30) not null,
StudentNumber int not null,
Class int not null,
Major varchar(4),
CONSTRAINT STUDENT_pk PRIMARY KEY(StudentNumber)
);
CREATE TABLE COURSE (
CourseName varchar(30) not null,
CourseNumber varchar(8) not null,
CreditHours int not null,
Department varchar(4),
CONSTRAINT COURSE_pk PRIMARY KEY(CourseNumber)
);
CREATE TABLE SECTION (
SectionIdentifier int not null,
CourseNumber varchar(8) not null,
Semester varchar(6) not null,
Year int not null,
Instructor varchar(30) not null,
CONSTRAINT SECTION_pk PRIMARY KEY(SectionIdentifier),
CONSTRAINT SECTION_cn_fk FOREIGN KEY(CourseNumber) REFERENCES
COURSE(CourseNumber) ON DELETE CASCADE ON UPDATE CASCADE
);
CREATE TABLE GRADE_REPORT (
StudentNumber int not null,
SectionIdentifier int not null,
Grade char(1),
CONSTRAINT GRADE_REPORT_pk PRIMARY
KEY(StudentNumber,SectionIdentifier),
CONSTRAINT GRADE_REPORT_sn_fk FOREIGN KEY(StudentNumber)
REFERENCES STUDENT(StudentNumber) ON DELETE CASCADE ON UPDATE CASCADE,
CONSTRAINT GRADE_REPORT_si_fk FOREIGN KEY(SectionIdentifier)
REFERENCES SECTION(SectionIdentifier) ON DELETE CASCADE ON UPDATE
CASCADE
);
CREATE TABLE PREREQUISITE (
CourseNumber varchar(8) not null,
PrerequisiteNumber varchar(8) not null,
CONSTRAINT PREREQUISITE_pk PRIMARY
KEY(CourseNumber,PrerequisiteNumber),
CONSTRAINT PREREQUISITE_cn_fk FOREIGN KEY(CourseNumber)
REFERENCES COURSE(CourseNumber) ON DELETE CASCADE ON UPDATE CASCADE,
CONSTRAINT PREREQUISITE_pn_fk FOREIGN KEY(PrerequisiteNumber)
REFERENCES COURSE(CourseNumber) ON DELETE CASCADE ON UPDATE CASCADE
); 

INSERT into STUDENT values
('Madhavan',154,3,'CS'),
('Ram',15,4,'CS'),
('Akash',17,4,'CS'),
('Reena',16,3,'EC');
INSERT into COURSE values
('DSA','16CS237',4,'CS'),
('DBMS','16CS154',4,'CS'),
('DMS','16CS243',3,'CS'),
('OS','16CS180',3,'CS');
INSERT into SECTION values
(1,'16CS243','3',2001,'Prof1'),
(2,'16CS237','3',2003,'Prof2'),
(3,'16CS154','5',2005,'Prof3'),
(4,'16CS243','3',2006,'Prof4'),
(5,'16CS237','3',2019,'Prof2'),
(6,'16CS180','3',2004,'Prof5');
INSERT into GRADE_REPORT values
(154,4,'C'),
(154,5,'B'),
(15,1,'A'),
(15,2,'A'),
(15,3,'A'),
(15,6,'A'),
(17,4,'C'),
(17,5,'B');
INSERT into PREREQUISITE values
('16CS180','16CS154'),
('16CS180','16CS243'),
('16CS154','16CS237');
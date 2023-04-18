create table member (
    id varchar(255) primary key,
    address varchar(255),
    gender char(1),
    name varchar(255),
    age int,
    email varchar(255),
    phone varchar(255)
);

create table book (
    isbn varchar(255) primary key,
    title varchar(255),
    lang varchar(50),
    year int,
    available int,
    author_id varchar(255),
    publisher_id varchar(255),
);

create table member_book (
    member_id varchar(255),
    book_id varchar(255),
    primary key (member_id, book_id),
    foreign key (member_id) references member(id),
    foreign key (book_id) references book(isbn)
);

partition by range(member) (
    partition p0 values less than (100000),
    partition p1 values less than (200000),
    partition p2 values less than (300000),
    partition p3 values less than MAXVALUE
);

partition by range(book) (
    partition p0 values less than (100000),
    partition p1 values less than (300000),
    partition p2 values less than MAXVALUE
);

-- Retrieve all records from certain partition

select * from book partition(p2);

-- Retrieve records from different partitions based on same condition

select * from book where book.year > 1950;

-- Retrieve records based on condition from a selective partition

select * from member partition(p0) where age > 50 and age < 70;

-- Perform optimizations by adding indexes

create index book_id_isbn on book(isbn);
create index member_id on member(id);

-- Perform queries similar queries to see performance improvements

-- Analysis queries

explain analyze select * from book where book.year > 1950;
explain analyze select * from member partition(p0) where age > 50 and age < 70;

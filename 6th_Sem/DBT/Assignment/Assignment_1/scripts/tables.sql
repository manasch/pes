create table book (
    isbn varchar(255) primary key,
    title varchar(255),
    lang varchar(50),
    year int,
    available int,
    author_id varchar(255),
    publisher_id varchar(255)
);

create table member (
    id varchar(255) primary key,
    address varchar(255),
    gender char(1),
    name varchar(255),
    age int,
    email varchar(255),
    phone varchar(255)
);

create table publisher (
    id varchar(255) primary key,
    established int,
    address varchar(255),
    name varchar(255)
);

create table author (
    authid varchar(255) primary key,
    name varchar(255),
    age int,
    gender char(1)
);

create table genre (
    id varchar(255) primary key,
    name varchar(255)
);

create table book_genre (
    bookid varchar(255),
    genreid varchar(255),
    foreign key (bookid) references book(isbn),
    foreign key (genreid) references genre(id)
);

create table author_publisher (
    authid varchar(255),
    publishid varchar(255),
    foreign key (authid) references author(authid),
    foreign key (publishid) references publisher(id)
);

create table member_borrow (
    memberid varchar(255),
    bookid varchar(255),
    issuedate varchar(255),
    returndate varchar(255),
    foreign key (memberid) references member(id),
    foreign key (bookid) references book(isbn)
);

-- Execute and analyze a select query that has a multi table join.

-- 1
select * from author natural join author_publisher join publisher on author_publisher.publishid = publisher.id;
explain analyze select * from author natural join author_publisher join publisher on author_publisher.publishid = publisher.id;

create index author_id on author_publisher(authid);
create index publish_id on author_publisher(publishid);

-- 2
select * from book join book_genre on book.isbn = book_genre.bookid join genre on book_genre.genreid = genre.id;
explain analyze select * from book join book_genre on book.isbn = book_genre.bookid join genre on book_genre.genreid = genre.id;

create index book_id_bg on book_genre(bookid);
create index genre_id_bg on book_genre(genreid);

-- Change the order of joins, use subqueries..

explain analyze select * from publisher join author_publisher on publisher.id = author_publisher.publishid join author on author_publisher.authid = author.authid;
explain analyze select * from genre join book_genre on genre.id = book_genre.genreid join book on book_genre.bookid = book.isbn;

explain analyze select * from (select * from book_genre where genreid in (select id from genre)) as B join book on B.bookid = book.isbn;

-- Create a query that uses a subquery and a correlated subquery.

-- Query the members who are older than the average age of the members
select avg(age) from member;
explain analyze select * from member where age > (select avg(age) from member);

-- Query authors who have published books with exactly 4 different publishers..
select * from author a1 where 4 = (select count(*) from author_publisher a2 where a1.authid = a2.authid);
explain analyze select * from author a1 where 4 = (select count(*) from author_publisher a2 where a1.authid = a2.authid);

-- Create a query that uses a materialized view and analyze its execution plan

select lang, count(*) from book group by lang;
create materialized view jap_books as (select * from book where lang = 'jap');

-- Without view
select author.name from book join author on book.author_id = author.authid where lang = 'jap';
explain analyze select author.name from book join author on book.author_id = author.authid where lang = 'jap';

-- With view
select author.name from jap_books join author on jap_books.author_id = author.authid;
explain analyze select author.name from jap_books join author on jap_books.author_id = author.authid;

-- Create a query that uses a function in the WHERE clause and analyze its execution plan.

create function duration (start date, return date)
returns int
language plpgsql
as
$$
declare
    ans int;
    start_epoch int;
    end_epoch int;
    diff_epoch int;
begin
    select extract(epoch from start) into start_epoch;
    select extract(epoch from return) into end_epoch;
    diff_epoch = end_epoch - start_epoch;
    ans = diff_epoch / (60 * 60 * 24);
    return ans;
end;
$$;

-- Query the books that were borrowed for more than 10 days

select memberid, bookid, issuedate, returndate, duration(issuedate, returndate) from member_borrow where duration(issuedate, returndate) > 10 limit 20;
explain analyze select memberid, bookid, issuedate, returndate, duration(issuedate, returndate) from member_borrow where duration(issuedate, returndate) > 10;

-- Create a query that uses a dynamic SQL statement and analyze its execution plan.

PREPARE get_book_count_by_lang(char(3)) as SELECT count(*) from book where lang = $1;
EXECUTE get_book_count_by_lang('eng');
explain analyze EXECUTE get_book_count_by_lang('spa');

-- Create a query that involves complex data types (e.g., arrays) and analyze its execution plan.

select * from genre;
select isbn, title, lang, year, available, name as _genre from book join book_genre on book.isbn = book_genre.bookid join genre on book_genre.genreid = genre.id where name = any(array['Action', 'Comedy', 'Crime', 'Isekai', 'Thriller']) limit 10;
explain analyze select isbn, title, lang, year, available, name as _genre from book join book_genre on book.isbn = book_genre.bookid join genre on book_genre.genreid = genre.id where name = any(array['Action', 'Comedy', 'Crime', 'Isekai', 'Thriller']);

-- Compare the performance of different indexing strategies (e.g., B-tree, hash) on a large table and record the results.

-- Query
explain analyze select * from publisher where name = 'Marvel Books';

-- Without index, with btree index, with hash index
create index pub_name on publisher using btree(name);
explain analyze select * from publisher where name = 'Marvel Books';

create index pub_name on publisher using hash(name);
explain analyze select * from publisher where name = 'Marvel Books';

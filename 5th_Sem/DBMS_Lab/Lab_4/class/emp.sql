SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";
savepoint s1;
insert into dept values(111, 'gggg', 1, '2020-6-7');
select * from dept;
savepoint s2;
delete from dept where dno = 105;
rollback to savepoint s2;
select * from dept;
commit;

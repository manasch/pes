Installed Hive on the VM.

Similar to Hands On 1, running scripts from the repo.

- [Hands On 2 [H2]](https://github.com/Cloud-Computing-Big-Data/UE20CS322-H2)

Similarly had 2 parts, HOME and CLASS, both of which are mentioned in the same link.

Task 3:

```sql
create table costs (id int, item_name String, item_cost int);

insert into costs values
(1, "chocolate", 100),
(2, "grape", 50),
(3, "chips", 10),
(4, "oranges", 80),
(5, "apples", 90),
(6, "chips", 20),
(7, "chocolate", 90),
(8, "grape", 100),
(9, "chips", 40),
(10, "oranges", 70),
(11, "apples", 90),
(12, "chips", 20);

update costs set item_cost = 30 where item_name = "chips";

delete from costs where item_cost in (select max(item_cost) from costs);

select item_name, count (*) from costs group by item_name;
```

# Write your MySQL query statement below
-- select distinct l1.num  as ConsecutiveNums
-- from Logs l1 
-- join Logs l2
--        on l1.id+1 =l2.id
-- join  Logs l3
-- on l2.id+1=l3.id
-- where l1.num =l2.num and l2.num=l3.num;

select 
DISTINCT num AS ConsecutiveNums
from (
    select num,
    lag(num,1) over() as prev1,
    lag(num,2) over() as prev2
    from Logs
)t
where num =prev1 and num =prev2;

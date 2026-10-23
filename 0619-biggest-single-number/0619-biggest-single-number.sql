# Write your MySQL query statement below
select 
max(num) as num
from MyNumbers
where num in (
    select num
    from MyNumbers
    group by num 
    having Count(*)=1
);
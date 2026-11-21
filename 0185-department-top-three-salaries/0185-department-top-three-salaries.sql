with cte as(select 
d.name as Department,
e.name as Employee,
e.Salary,
dense_rank() over(partition by d.name order by e.salary desc) as r
from Employee e
join Department d
on e.departmentId=d.id)

select
Department,
Employee,
Salary
from cte
where r<=3;
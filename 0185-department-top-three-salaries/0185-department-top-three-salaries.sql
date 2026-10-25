# Write your MySQL query statemen
with cte as(
    select
    e.name as Employee,
     e.salary as Salary,
     d.name as Department,
     dense_rank() over(partition by departmentId order By salary desc) as rnk
     from Employee e
    join Department d 
    on e.departmentId =d.id
)
select 
    Department,Employee,Salary from cte
    where rnk<=3;
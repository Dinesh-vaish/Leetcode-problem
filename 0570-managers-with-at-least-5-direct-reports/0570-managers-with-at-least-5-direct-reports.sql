select 
e.name
from Employee e
join Employee m
on m.managerId =e.id
group by e.id,e.name
having count(*)>=5



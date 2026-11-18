with manager as (
    select
    m.id,
    m.name as name,
    count(m.id) as totla_employee
    from Employee e
    join Employee m
    on m.id =e.managerId
    group by m.name,m.id
)

select name from manager
where totla_employee>=5;
select e.name from (
    select e.id,e.name,e.department
    from employee e
    join employee m on e.id=m.managerid
    group by e.id
    having count(m.managerid)>=5
)e

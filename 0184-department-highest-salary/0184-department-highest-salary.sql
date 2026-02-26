
select d.name as department,e.name as employee ,e.salary
from(
    select *,
    dense_rank() oveR(partition by departmentid order by salary desc) rnk
    from employee
)e
join department d on e.departmentid=d.id
where rnk=1;
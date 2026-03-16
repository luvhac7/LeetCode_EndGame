select d.name as Department,e.name as Employee,e.salary as Salary
from(
    select *,
    dense_rank() over(partition by departmentid order by salary desc)as rnk
    from employee 
)e
join department d on e.departmentid=d.id
where rnk<=3;
select d.name as department,e.name as Employee,e.Salary
from(
    select * ,
    dense_rank() over(partition by departmentid order by salary desc) rnk
    from employee 
)e
join department d on d.id=e.departmentid
where rnk<=3;

# Write your MySQL query statement below
with cte as(
    select department.name as department,
    employee.name as employee,
    employee.salary as salary,
    dense_rank() over(partition by department.name order by salary desc)
    as salaryrank from employee
    inner join department on employee.departmentid=department.id
)
select department,employee,salary
from cte
where salaryrank<=3;
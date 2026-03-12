with cte as(
    select d.name as department,e.name as Employee ,e.salary as salary ,
    dense_rank() over(partition by d.name order by e.salary desc) as rnk
    from employee e
       join department d on e.departmentid=d.id
)
select department,employee,salary from cte
where rnk<2;
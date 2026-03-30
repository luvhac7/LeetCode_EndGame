CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  RETURN (
with cte as(
select salary,
dense_rank() oveR(order by salary desc) as rn
from employee
)
select salary from cte 
where rn=n
limit 1
  );
END
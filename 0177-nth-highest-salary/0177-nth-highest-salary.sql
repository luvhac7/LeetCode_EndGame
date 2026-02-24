CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
DETERMINISTIC
BEGIN
  DECLARE offset_val INT;
  SET offset_val = N - 1;
  RETURN (
        select distinct salary
        from employee
        order by salary desc
        limit 1 offset offset_val
  );
END;
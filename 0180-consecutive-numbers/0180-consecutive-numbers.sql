select distinct num as ConsecutiveNums 
from(
    select num,
    lag(num) over(order by id) as p,
    lead(num)over(order by id) as n
    from logs
)z
where num=p and num=n;
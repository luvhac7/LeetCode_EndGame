# Write your MySQL query statement below
#select distinct a.num as ConsecutiveNums from logs a
#join logs b on a.id=b.id+1 and a.num=b.num
#join logs c on a.id=c.id+2 and a.num=c.num
-- join logs d on a.id=d.id+3 and a.num=d.num

select distinct num as consecutivenums 
from (
    select 
        num,
        lag(num,1) over(order by id) as p1,
        lag(num,2)over (order by id) as p2
        from logs
)t
where num=p1
and
num=p2
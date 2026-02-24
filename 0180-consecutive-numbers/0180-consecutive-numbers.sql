# Write your MySQL query statement below
# return 3 time ->no that occ
#sel distinct no from that table 
# then we use wf -> lag()
#check end num=n1 and num =n2
#simify:
select distinct num as ConsecutiveNums
from(
    select num,
    lag(num) over(order by id) as n1,
    lead(num) over(order by id) as n2
    from logs
)x
where num=n1 and num=n2;
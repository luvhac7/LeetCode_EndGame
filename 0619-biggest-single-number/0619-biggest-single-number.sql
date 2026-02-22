# Write your MySQL query statement below
select if(count(num)=1,num,NULL) as num
from mynumbers
group by num
order by num desc
limit 1
select s.user_id,
round(avg(case when action='confirmed' then 1 else 0 end),2) as confirmation_rate
from signups s
left join confirmations c on c.user_id=s.user_id
group by s.user_id
order by confirmation_rate
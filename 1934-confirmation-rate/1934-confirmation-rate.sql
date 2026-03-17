select s.user_id,
round(avg(case when c.action='confirmed'then 1 else 0 end),2)as confirmation_rate
from signups s
left join confirmations c
on s.useR_id=c.useR_id
group by s.useR_id
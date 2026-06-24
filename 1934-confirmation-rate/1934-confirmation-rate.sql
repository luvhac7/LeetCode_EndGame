select a.user_id,round(ifnull(avg(action='confirmed'),0),2)as confirmation_rate
from signups as a left join confirmations as b on a.user_id=b.user_id
group by a.user_id
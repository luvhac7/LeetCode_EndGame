select u.user_id as buyer_id,u.join_date,
(select count(*) from orders o2
where o2.buyer_id=u.user_id
and year(ordeR_Date)="2019"
)
as orders_in_2019
from users u
group by u.user_id
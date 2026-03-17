with cte as(
    select requester_id as id from requestaccepted
    union all
    select accepter_id as id from requestaccepted
)
select id, count(*)as num
from cte
group by id
order by count(*) desc
limit 1;
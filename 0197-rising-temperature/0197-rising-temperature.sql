with cte1 as(
select id  as Id from weather as cur
where exists(
    select 1 from weather as prev
    where cur.temperature>prev.temperature
    and datediff(cur.recorddate,prev.recorddate)=1
)
)
,cte2 as(
    select w2.id from weather w1
    join weather w2 on w2.temperature>w1.temperature
    and datediff(w2.recorddate,w1.recorddate)=1  
)
select * from cte2;
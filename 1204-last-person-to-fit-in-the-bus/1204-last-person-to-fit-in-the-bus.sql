with cte as(
    select person_name,turn,
    sum(weight) over(order by turn) as tw
    from queue
)
select person_name from cte
where tw<=1000
order by tw desc
limit 1
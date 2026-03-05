select person_name from(
    select person_name,sum(weight) oveR(order by turn)as tw
    from queue
)as cs
where tw<=1000
order by tw desc
limit 1;
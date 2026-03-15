with cte as(
    select person_name,
    sum(weight) oveR(order by turn) as x
    from queue
)
select person_name from cte
where x<=1000
order by x desc
limit 1;
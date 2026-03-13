with cte as(
    select turn,person_name ,
    sum(weight) over(order by turn)as rnk
    from queue
)
select person_name from cte
where rnk<=1000
order by rnk desc
limit 1;
with cte as(
    select *,
    rank() over(partition by email order by id)as rn
    from person
)
delete from person
where id in(
    select id from cte where rn>1
)
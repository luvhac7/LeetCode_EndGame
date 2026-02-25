delete from person
where id not in(
    select id from(
    select id,
    row_number() over(partition by email order by id) as rnk
    from person
)t
where rnk=1
);
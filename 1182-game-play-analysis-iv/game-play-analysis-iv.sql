with firstlogin as(
    select player_id,min(event_date)as first_login from activity
    group by player_id
),
consecutivelogin as(
    select a.player_id from Activity a 
    join firstlogin fl on a.player_id=fl.player_id
    and a.event_date=date_add(fl.first_login,interval 1 day)
)
select round(
    count(distinct cl.player_id)*1/count(distinct fl.player_id),
    2)as fraction
    from firstlogin fl left join consecutivelogin cl
    on fl.player_id=cl.player_id;
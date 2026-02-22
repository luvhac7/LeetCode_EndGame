# Write your MySQL query statement below
select round(sum(a.tiv_2016),2) as tiv_2016
from insurance a
where a.tiv_2015 in(
    select b.tiv_2015 from insurance b
    where b.pid!=a.pid
)
and (a.lat,a.lon) not in(
    select c.lat,c.lon from insurance c
    where c.pid!=a.pid
);
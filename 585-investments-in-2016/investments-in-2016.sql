select round(sum(a.tiv_2016),2)as tiv_2016
from insurance a
where a.tiv_2015 in(
    select b.tiv_2015 from insurance b
    where b.pid!=a.pid
)
and (a.lat,a.lon) not in(
    select x.lat,x.lon from insurance x
    where x.pid!=a.pid
)

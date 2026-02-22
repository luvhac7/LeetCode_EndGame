# Write your MySQL query statement below
delete p1
from person p1
inner join person p2 on p2.email=p1.email and p1.id>p2.id;
with cte as(
select p.product_name,
sum(o.unit)as unit
from orders o 
inner join products p on o.product_id=p.product_id
where o.order_date between '2020-02-01' and '2020-02-29'
group by p.product_id
)
select * from cte
where unit>=100;
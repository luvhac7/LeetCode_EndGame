select 
round(100*sum(case when b.min_order_Date=b.min_delivery_date then 1 else 0 end)/count(*),2)
as immediate_percentage
from(
    select min(order_Date) as min_order_date,
    min(customer_pref_delivery_date)as min_delivery_Date
    from delivery
    group by customeR_id
)b;
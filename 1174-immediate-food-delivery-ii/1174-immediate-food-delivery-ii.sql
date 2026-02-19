#optmized soln
select round(sum(case when date(order_date)=date(customer_pref_delivery_date)then 1 else 0 end)*100/count(*),2) immediate_percentage
from (
    select *,row_number() over(partition by customer_id order by order_date) as rn
    from delivery
)t
where rn=1
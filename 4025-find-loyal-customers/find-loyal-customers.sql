with cte as(
select customer_id,
sum(case when transaction_type= 'purchase' then 1 else 0 end)as total_p,
sum(case when transaction_type = 'refund' then 1 else 0 end)/count(transaction_type) as refund_rate,
datediff(max(transaction_date),min(transaction_date)) as order_rate
from customer_transactions
group by customer_id
)
select customer_id
from cte
where refund_rate<.20 and ordeR_rate>=30 and total_p>=3

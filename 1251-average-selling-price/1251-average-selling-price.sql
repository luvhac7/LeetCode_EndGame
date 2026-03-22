select p.product_id,
round(ifnull(sum(p.price*u.units)/sum(u.units),0),2)as average_price from prices p
left join unitssold u on p.product_id=u.product_id
and u.purchase_Date between p.start_Date and p.end_Date
group by p.product_id 
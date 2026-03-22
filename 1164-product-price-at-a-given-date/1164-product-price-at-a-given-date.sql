select distinct products.product_id,coalesce(latest_prices.new_price,10) as price
from products
left join
#latest price
(select product_id,new_price from products
where(product_id,change_date) in
# select latest prices
(select  product_id,max(change_date) as change_date from products
where change_date<='2019-08-16'
group by product_id)) latest_prices
on products.product_id=latest_prices.product_id
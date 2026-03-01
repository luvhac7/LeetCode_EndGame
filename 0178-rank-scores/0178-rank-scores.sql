
 select score,
 dense_rank()oveR(order by score desc) as
 'rank' from scores;
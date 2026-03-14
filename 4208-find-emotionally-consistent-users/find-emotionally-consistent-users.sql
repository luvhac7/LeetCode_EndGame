with cte1 as(
	select user_id,reaction,count(distinct content_id) as num
	from reactions
	group by user_id,reaction
	),
	
	cte2 as(
	select user_id,reaction,num,
	sum(num)over(partition by user_id)as content_reactions,
	round(num*1.0/sum(num) over(partition by useR_id),2) as reaction_ratio,
	row_number() over(partition by user_id order by num desc)as rnk
	from cte1)
	select user_id,
	reaction as dominant_reaction,
reaction_ratio from cte2
where content_reactions>=5 and reaction_ratio>=0.60 and rnk=1
order by reaction_ratio desc;
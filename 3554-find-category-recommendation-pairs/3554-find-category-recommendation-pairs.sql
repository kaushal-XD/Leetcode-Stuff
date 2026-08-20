# Write your MySQL query statement below
with filter as
(
    select user_id, category
    from productpurchases p1 
    inner join productinfo p2
    on p1.product_id = p2.product_id
)
select f1.category as category1, f2.category as category2 , count(distinct f1.user_id) as customer_count
from filter f1 
inner join filter f2
    on f1.user_id = f2.user_id 
    and f1.category < f2.category
group by f1.category, f2.category 
having count(distinct f1.user_id) >= 3
order by customer_count desc , category1, category2 


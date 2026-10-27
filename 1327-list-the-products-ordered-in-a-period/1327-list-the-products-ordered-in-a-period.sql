# Write your MySQL query statement below
SELECT
product_name,
SUM(unit) as unit
FROM Products JOIN Orders Using(product_id)
WHERE MONTH(order_date) =2 and YEAR(order_date)=2020
group by product_name
having unit>=100;
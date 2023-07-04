# Write your MySQL query statement below
SELECT p.product_name, SUM(o.unit) as unit
FROM Products as p
LEFT JOIN Orders as o ON p.product_id = o.product_id
WHERE o.order_date BETWEEN "2020-02-01" AND "2020-02-29"
GROUP BY o.product_id
HAVING SUM(o.unit)>=100

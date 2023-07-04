# Write your MySQL query statement below
SELECT p.product_id, ROUND(SUM(p.price*u.units)/SUM(u.units), 2) as average_price
FROM Prices as p
JOIN UnitsSold as u ON p.product_id = u.product_id
AND u.purchase_date BETWEEN p.start_date AND p.end_date
GROUP BY p.product_id;
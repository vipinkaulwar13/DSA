# Write your MySQL query statement below
SELECT DISTINCT o.email as Email
FROM Person as o, Person as d
WHERE o.id <> d.id AND o.email = d.email
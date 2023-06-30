# Please write a DELETE statement and DO NOT write a SELECT statement.
# Write your MySQL query statement below
DELETE p
FROM Person as p, Person as d
WHERE p.id>d.id AND p.email = d.email

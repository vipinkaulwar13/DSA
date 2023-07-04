# Write your MySQL query statement below
SELECT e.unique_id, m.name
FROM Employees as m
LEFT JOIN EmployeeUNI as e ON m.id = e.id

# Write your MySQL query statement below
SELECT DISTINCT a.player_id, MIN(a.event_date) as first_login
FROM Activity as a
GROUP BY a.player_id
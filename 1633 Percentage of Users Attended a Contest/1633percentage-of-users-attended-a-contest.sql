# Write your MySQL query statement below
SELECT  contest_id,
ROUND(COUNT(DISTINCT user_id)*100 / (select COUNT(user_id) from Users ) ,2) AS percentage
FROM Register 
GROUP BY contest_id 
order by percentage DESC, contest_id 

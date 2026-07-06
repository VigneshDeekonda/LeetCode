# Write your MySQL query statement below
-- select 
-- l1.num as ConsecutiveNums 
-- from Logs l1, Logs l2,Logs l3
-- where l1.id - l2.id = 1
-- and l2.id - l3.id = 1
-- and l1.num = l2.num
-- and l2.num = l3.num
-- and l3.num = l1.num
-- group by l1.num;


WITH cte AS 
(select *,LEAD(num,1) OVER() AS next_1,
LEAD(num,2) OVER() AS next_2
FROM logs)

SELECT distinct num as ConsecutiveNums 
FROM cte
where num = next_1
and num = next_2
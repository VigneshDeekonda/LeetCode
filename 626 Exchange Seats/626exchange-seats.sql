# Write your MySQL query statement below
With cte AS
(Select *, LEAD(id) OVER(order by id) as next,lag(id) over(order by id) prev
FROM Seat)
select case when((id % 2 = 1) AND next is not null) then next
when(id % 2 = 0) then prev
else id end as id,student
from cte
order by id

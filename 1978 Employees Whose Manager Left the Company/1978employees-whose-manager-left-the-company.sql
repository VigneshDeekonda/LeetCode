# Write your MySQL query statement below
select e1.employee_id 
from Employees e1
where e1.salary < 30000
and manager_id is not null
and manager_id not in 
(select employee_id 
from employees)
order by e1.employee_id 
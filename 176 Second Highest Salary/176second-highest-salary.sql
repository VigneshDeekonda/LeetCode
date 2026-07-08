# Write your MySQL query statement below
SELECT(
  SELECT distinct salary 
  FROM Employee 
  ORDER BY salary desc
  LIMIT 1,1) as SecondHighestSalary
# Write your MySQL query statement below
SELECT DISTINCT author_id AS id
FROM Views
WHERE author_id = viewer_id
ORDER BY author_id;

#since there is a no primary key therefor i took distinct values to check the unrepeated data
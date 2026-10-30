# Write your MySQL query statement below
SELECT e.name
FROM Employee e 
JOIN Employee em
ON em.managerId = e.id
GROUP BY em.managerId
HAVING COUNT(em.managerId) >= 5;
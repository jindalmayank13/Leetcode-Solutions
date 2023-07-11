with base as
(SELECT 
 visited_on,
 sum(amount) as amount
 FROM Customer
 GROUP BY 1)


SELECT c1.visited_on,
round(sum(c2.amount),2) as amount,
round(avg(c2.amount),2) as average_amount
FROM base c1 
JOIN base c2 on datediff(c1.visited_on, c2.visited_on ) between 0 and 6
GROUP BY 1
HAVING count(distinct c2.visited_on) = 7
ORDER BY 1
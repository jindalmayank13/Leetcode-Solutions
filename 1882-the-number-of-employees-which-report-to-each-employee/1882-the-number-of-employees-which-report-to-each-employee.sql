
SELECT M.employee_id, M.name, COUNT(*) as reports_count, ROUND(AVG(E.age),0) as average_age
FROM Employees as E JOIN Employees as M
ON E.reports_to = M.employee_id
GROUP BY E.reports_to
ORDER BY M.employee_id ASC

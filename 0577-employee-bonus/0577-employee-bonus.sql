# Write your MySQL query statement below
select name ,bonus from employee e left join bonus b on 
e.emPID= b.empID where b.bonus<1000 or b.bonus is null;

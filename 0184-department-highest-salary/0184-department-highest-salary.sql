# Write your MySQL query statement below
select d.name as department, e.name as Employee , e.salary
from employee as e left join department as d
on e.departmentid = d.id
where salary = (select max(e1.salary) from employee as e1 where e1.departmentid = e.departmentid)
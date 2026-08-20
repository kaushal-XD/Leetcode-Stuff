# Write your MySQL query statement below
select d.name as department, e.name as Employee , e.salary
from employee as e join 
(
    select e1.departmentid as id, max(e1.salary) as mxsalary
    from employee e1 
    group by e1.departmentid
) as t
on e.departmentid = t.id and e.salary = t.mxsalary
join department as d on 
d.id = e.departmentid

# Write your MySQL query statement below
select d.name as department, e.name as employee, e.salary as salary
from employee e join department d
on e.departmentid = d.id
where 3 >= (
    select count(distinct e2.salary )
    from employee e2
    where e2.salary >= e.salary and e.departmentid = e2.departmentid
)
ORDER BY
    Department, Salary DESC;
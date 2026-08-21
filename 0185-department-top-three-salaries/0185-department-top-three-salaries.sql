with temp as
(
    select d.name as 'Department' , e.name as 'Employee' , e.salary as 'Salary',
    dense_rank() over(partition by e.departmentid order by e.salary desc) as trank
    from employee e left join department d 
    on e.departmentid = d.id
)

select department , employee , salary 
from temp 
where trank <= 3
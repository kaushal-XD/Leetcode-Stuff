with temp as
(
    select name , salary , departmentid, 
    dense_rank() over(partition by departmentid order by salary desc)
    as trank
    from employee
)

select d.name as department , t.name as employee , t.salary salary 
from temp t left join department d 
on t.departmentid = d.id
where trank <= 3

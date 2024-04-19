# Write your MySQL query statement below
select distinct l1.num as ConsecutiveNums
from logs l1
join logs l2 on l1.id+1 = l2.id
join logs l3 on l1.id+2 = l3.id
where l1.num=l2.num and l2.num=l3.num
# Write your MySQL query statement below
select if(count(num) = 1, num, null) as num from MyNumbers
group by num order by num desc limit 1
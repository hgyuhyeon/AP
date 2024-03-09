# Write your MySQL query statement below
select a1.machine_id, round(avg(a2.timestamp - a1.timestamp), 3) as processing_time 
from Activity as a1, Activity as a2
where a1.activity_type = 'start' and a2.activity_type = 'end'
and a1.process_id = a2.process_id and a1.machine_id = a2.machine_id
group by a1.machine_id order by a1.machine_id;
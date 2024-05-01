# Write your MySQL query statement below
select row_number() over() id, student # row_number() 결과에 숫자 순서대로 붙여줌, over() 는 row_number와 함께 쓰는 함수(정렬 기준)
from Seat
order by if(mod(id,2)=1, id+1,id-1)
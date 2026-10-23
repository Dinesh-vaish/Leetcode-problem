/* Write your T-SQL query statement below */
select 
x,y,z,
CASE    
    WHEN x+y>z
    AND  x+z>y
    AND  y+z>x
    then 'Yes'
    else 'No'
    end
AS triangle
from Triangle;
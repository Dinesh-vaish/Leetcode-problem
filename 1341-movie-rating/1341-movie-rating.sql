with cte as( 
select 
*
from MovieRating mr
left join Movies m
using (Movie_id)
left join Users u
using (user_id)
)
( 
select name as results from cte
group by name,user_id
order by count(*) desc, name
limit 1
)

union all
  (   select title as results
    from cte 
    where date_format(created_at,'%Y-%m')='2020-02'
    group by title,movie_id
    order by avg(rating) desc,title
    limit 1
   ) ;


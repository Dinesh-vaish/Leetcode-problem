/* Write your T-SQL query statement below */
SELECT
FORMAT(trans_date,'yyyy-MM') as month,
country,
count(*) as trans_count,
  SUM(CASE WHEN state = 'approved' THEN 1 ELSE 0 END) as approved_count,
  sum(amount) as trans_total_amount,
  
    sum(
        case 
            when state='approved'
            then amount
        else 0
        end
    )as approved_total_amount 

from Transactions
group by FORMAT(trans_date,'yyyy-MM'),country;

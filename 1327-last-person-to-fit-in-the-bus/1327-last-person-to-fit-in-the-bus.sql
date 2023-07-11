select
    person_name
from    
    (
        select
            *
            , sum(weight) over (order by Turn) as total_sum
        from queue
    ) t -- every derived table must have its own alias
where total_sum <= 1000
order by turn desc
limit 1
WITH SwappedSeats AS(

    SELECT id,student, CASE

                        WHEN id%2=1 AND id<(SELECT MAX(id) FROM Seat)

                        THEN id+1

                        WHEN id%2=0

                        THEN id-1

                        ELSE id

                       END AS new_id

    FROM Seat

)

SELECT new_id AS id, student

FROM SwappedSeats

ORDER BY id;
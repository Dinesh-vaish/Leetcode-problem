(
    SELECT u.name AS results
    FROM MovieRating mr
    JOIN Users u
        ON mr.user_id = u.user_id
    GROUP BY u.user_id, u.name
    ORDER BY COUNT(*) DESC, u.name ASC
    LIMIT 1
)

UNION ALL

(
    SELECT m.title AS results
    FROM MovieRating mr
    JOIN Movies m
        ON mr.movie_id = m.movie_id
    WHERE YEAR(created_at) = 2020
      AND MONTH(created_at) = 2
    GROUP BY m.movie_id, m.title
    ORDER BY AVG(mr.rating) DESC, m.title ASC
    LIMIT 1
);
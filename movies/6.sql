--6.sql
SELECT AVG(ALL rating) FROM ratings WHERE movie_id IN (SELECT id FROM movies WHERE year = 2012);

--4.sql
SELECT COUNT(title) FROM movies WHERE movies.id IN (SELECT movie_id FROM ratings WHERE rating = 10);

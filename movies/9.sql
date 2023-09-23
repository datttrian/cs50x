--9.sql
SELECT DISTINCT name FROM people, movies, stars
WHERE people.id = stars.person_id
AND stars.movie_id = movies.id
AND year = 2004 ORDER BY birth;

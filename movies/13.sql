--13.sql
SELECT DISTINCT(name) FROM people
JOIN stars ON stars.person_id=people.id
WHERE id IN (SELECT stars.person_id FROM stars WHERE stars.movie_id
IN (SELECT stars.movie_id FROM stars WHERE stars.person_id = (
    SELECT id FROM people WHERE name = "Kevin Bacon" AND birth = 1958)))
AND name != "Kevin Bacon";

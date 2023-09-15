-- write a SQL query to list the names of all people who starred in a movie released in 2004, ordered by birth year.
-- your query should output a table with a single column for the name of each person.
-- people with the same birth year may be listed in any order.
-- no need to worry about people who have no birth year listed, so long as those who do have a birth year are listed in order.
-- if a person appeared in more than one movie in 2004, they should only appear in your results once.
SELECT
    people.name
FROM
    people
    JOIN stars ON stars.person_id = people.id
    JOIN movies ON stars.movie_id = movies.id
WHERE
    movies.year = 2004
GROUP BY
    people.name
ORDER BY
    people.birth ASC
-- write a SQL query to list the names of all people who have directed a movie that received a rating of at least 9.0.
-- your query should output a table with a single column for the name of each person.
-- if a person directed more than one movie that received a rating of at least 9.0, they should only appear in your results once.
SELECT
    people.name
FROM
    people
    JOIN directors ON people.id = directors.person_id
    JOIN movies ON directors.movie_id = movies.id
    JOIN ratings ON ratings.movie_id = movies.id
WHERE
    ratings.rating > 8.9
GROUP BY
    people.name
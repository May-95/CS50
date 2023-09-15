-- write a SQL query to list the titles of all movies in which both Bradley Cooper and Jennifer Lawrence starred.
-- Your query should output a table with a single column for the title of each movie.
-- You may assume that there is only one person in the database with the name Bradley Cooper.
-- You may assume that there is only one person in the database with the name Jennifer Lawrence.
SELECT
    movies.title
FROM
    movies
    JOIN stars ON stars.movie_id = movies.id
    JOIN people ON stars.person_id = people.id
WHERE
    people.name = "Bradley Cooper"
INTERSECT
SELECT
    movies.title
FROM
    movies
    JOIN stars ON stars.movie_id = movies.id
    JOIN people ON stars.person_id = people.id
WHERE
    people.name = "Jennifer Lawrence"
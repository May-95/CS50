-- write a SQL query to list the titles of all movies with a release date on or after 2018, in alphabetical order.
-- your query should output a table with a single column for the title of each movie.
-- movies released in 2018 should be included, as should movies with release dates in the future.
SELECT
    title
FROM
    movies
WHERE
    YEAR >= 2018
ORDER BY
    title asc
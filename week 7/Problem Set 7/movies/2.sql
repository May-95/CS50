-- write a SQL query to determine the birth year of Emma Stone.
-- your query should output a table with a single column and a single row (not counting the header) containing Emma Stone’s birth year.
-- you may assume that there is only one person in the database with the name Emma Stone.
SELECT
    birth
FROM
    people
WHERE
    name = "Emma Stone"
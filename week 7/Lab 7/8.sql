-- write a SQL query that lists the names of the songs that feature other artists.
-- songs that feature other artists will include “feat.” in the name of the song.
-- your query should output a table with a single column for the name of each song.

SELECT
    name
FROM
    songs
WHERE
    name LIKE '%feat%'
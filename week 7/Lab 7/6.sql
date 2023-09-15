-- write a SQL query that lists the names of songs that are by Post Malone.
-- your query should output a table with a single column for the name of each song.
-- you should not make any assumptions about what Post Malone’s artist_id is.

SELECT
    songs.name
FROM
    songs
    JOIN artists ON songs.artist_id = artists.id
WHERE
    artists.name = 'Post Malone';
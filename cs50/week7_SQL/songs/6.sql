-- SELECT name FROM songs WHERE artists.name = 'Post Malone'

-- LEFT JOIN artists ON songs.artist_id = artists.id

SELECT name FROM songs WHERE artist_id = (SELECT id FROM artists WHERE name = 'Post Malone');
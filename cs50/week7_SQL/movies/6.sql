-- SELECT AVG(rating) FROM ratings WHERE movie_id = (SELECT id FROM movies WHERE year = 2012);
SELECT AVG(rating) FROM ratings JOIN movies ON movies.id = ratings.movie_id WHERE year = 2012;
SELECT name FROM people 
JOIN stars ON people.id = stars.person_id
JOIN movies ON stars.movie_id = movies.id
WHERE movies.title = 'Toy Story';

-- SELECT name
-- FROM movies, stars, people
-- WHERE movies.id = stars.movie_id
-- AND people.id = stars.person_id
-- AND title = "Toy Story";
-- https://github.com/mancuoj/CS50x/blob/master/Week7/1-movies.sql
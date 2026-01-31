-- 10. Names of all directors who have directed a movie that got a rating of at least 9.0
SELECT DISTINCT people.name FROM people JOIN directors ON directors.person_id = people.id
 JOIN movies ON directors.movie_id = movies.id
 JOIN ratings on ratings.movie_id = movies.id WHERE ratings.rating >= 9.0;

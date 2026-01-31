-- 12. Titles of all of movies in which both Jennifer Lawrence and Bradley Cooper starred
SELECT movies.title from movies
 JOIN stars ON stars.movie_id = movies.id
  JOIN people ON stars.person_id = people.id
   WHERE people.name = "Jennifer Lawrence"
   AND movies.id IN
    (SELECT movie_id from stars
     JOIN people ON stars.person_id = people.id
      WHERE people.name = "Bradley Cooper");

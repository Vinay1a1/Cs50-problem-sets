-- 8. Names of people who starred in Toy Story
SELECT people.name from people JOIN stars ON stars.person_id = people.id WHERE movie_id=(SELECT id from movies WHERE title = "Toy Story");

SELECT COUNT(title) FROM movies
JOIN ratings on movies.id = ratings.movie_id
WHERE rating = 10;
© 2020 GitHub, Inc.
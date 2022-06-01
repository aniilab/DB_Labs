SELECT G.Name
FROM Genres AS G
WHERE NOT EXISTS(
	(SELECT MG.MovieId
	FROM MoviesGenres AS MG INNER JOIN Movies
	ON MG.MovieId = Movies.Id
	WHERE Movies.IMDbRate>Rating
	)
	EXCEPT(
	SELECT MG2.MovieId
	FROM MoviesGenres AS MG2
	WHERE MG2.GenreId = G.Id
	)
);
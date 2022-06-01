SELECT DISTINCT Genres.Name
FROM Genres INNER JOIN
	(MoviesGenres INNER JOIN 
		(Movies INNER JOIN Productions
		ON Movies.ProductionId = Productions.Id)
	ON MoviesGenres.MovieId = Movies.Id)
ON Genres.Id = MoviesGenres.GenreId
WHERE(Productions.Name = ProductionName);
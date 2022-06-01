SELECT DISTINCT Directors.Name 
		FROM Directors INNER JOIN 
			(DirectorMovies INNER JOIN 
				(Movies INNER JOIN 
					(MoviesGenres INNER JOIN Genres
					ON MoviesGenres.GenreId=Genres.Id)
				ON Movies.Id=MoviesGenres.MovieId)
			ON Movies.Id=DirectorMovies.MovieId)
		ON Directors.Id=DirectorMovies.DirectorId
WHERE Genres.Name=GenreName;

SELECT DISTINCT Movies.Name
FROM Movies
WHERE CountOfGenres <
	(SELECT COUNT(MoviesGenres.GenreId)
	 FROM MoviesGenres
	 WHERE MoviesGenres.MovieId = Movies.Id);
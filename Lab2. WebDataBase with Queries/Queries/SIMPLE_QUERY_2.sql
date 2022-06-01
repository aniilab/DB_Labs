--Знайти назви усіх фільмів та їхні роки випуску заданого жанру, рік випуску яких більше заданого.
SELECT Movies.Name, Movies.ProdYear
FROM Movies
WHERE Movies.Id IN
	(SELECT MoviesGenres.MovieId
	 FROM MoviesGenres INNER JOIN Genres
	 ON Genres.Id = MoviesGenres.GenreId
	 WHERE Genres.Name = GenreName AND Movies.ProdYear > MovieYear);
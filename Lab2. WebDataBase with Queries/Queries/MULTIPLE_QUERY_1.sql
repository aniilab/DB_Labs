DECLARE @M nvarchar(50) = MovieName;

SELECT M.Name
FROM Movies M
WHERE M.Name != @M
AND NOT EXISTS
((SELECT MoviesGenres.GenreId
  FROM MoviesGenres
  WHERE MoviesGenres.MovieId = M.Id)
 EXCEPT
 (SELECT MoviesGenres.GenreId
  FROM MoviesGenres
	INNER JOIN Movies ON MoviesGenres.MovieId = Movies.Id
  WHERE Movies.Name = @M))
AND NOT EXISTS
((SELECT MoviesGenres.GenreId
  FROM MoviesGenres
	INNER JOIN Movies ON MoviesGenres.MovieId = Movies.Id
  WHERE Movies.Name = @M)
 EXCEPT
(SELECT MoviesGenres.GenreId
  FROM MoviesGenres
  WHERE MoviesGenres.MovieId = M.Id));

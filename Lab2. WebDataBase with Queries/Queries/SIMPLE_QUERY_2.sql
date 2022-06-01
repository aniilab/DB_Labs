--������ ����� ��� ������ �� ��� ���� ������� �������� �����, �� ������� ���� ����� ��������.
SELECT Movies.Name, Movies.ProdYear
FROM Movies
WHERE Movies.Id IN
	(SELECT MoviesGenres.MovieId
	 FROM MoviesGenres INNER JOIN Genres
	 ON Genres.Id = MoviesGenres.GenreId
	 WHERE Genres.Name = GenreName AND Movies.ProdYear > MovieYear);
--Знайти назви усіх фільмів, в яких знімається актор із заданим ім'ям
SELECT DISTINCT Movies.Name
FROM Movies
WHERE Movies.Id IN
	(SELECT ActorsInMovies.MovieId
	 FROM ActorsInMovies INNER JOIN Actors
	 ON Actors.Id = ActorsInMovies.ActorId
	 WHERE Actors.Name = ActorName);
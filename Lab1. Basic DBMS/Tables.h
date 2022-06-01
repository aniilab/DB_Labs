#ifndef Tables_h
#define Tables_h

#include <string>
#include <map>

using namespace std;

class Movie {
private:
	std::string m_name;
	std::string m_duration;
	std::string m_rate;
	std::string m_year;
	std::string m_production_id;
	static int Movie_ID;
	int m_id;

public:
	Movie() {

	}
	Movie(std::string name, std::string duration, std::string rate, std::string year, std::string production_id) : m_name(name), m_duration(duration), m_rate(rate), m_year(year), m_production_id(production_id) {
		Movie_ID++;
		m_id = Movie_ID;
	}
	std::string Get_name() {
		return m_name;
	}
	void Set_name(std::string name) {
		m_name = name;
	}
	std::string Get_duration() {
		return m_duration;
	}
	void Set_duration(std::string duration) {
		m_duration = duration;
	}
	std::string Get_rate() {
		return m_rate;
	}
	void Set_rate(std::string rate) {
		m_rate = rate;
	}
	std::string Get_year() {
		return m_year;
	}
	void Set_year(std::string year) {
		m_year = year;
	}
	std::string Get_production_id() {
		return m_production_id;
	}
	void Set_production_id(std::string production_id) {
		m_production_id = production_id;
	}
	void Change_ID(int new_id) {
		m_id = new_id;
		Movie_ID = new_id;
	}
	int Get_ID() {
		return m_id;
	}
	std::string Get_table_name() {
		return "Movie";
	}
};

class Genre {
private:
	std::string m_name;
	static int Genre_ID;
	int m_id;

public:
	Genre() {

	}
	Genre(std::string name) : m_name(name) {
		Genre_ID++;
		m_id = Genre_ID;
	}
	void Change_ID(int new_id) {
		m_id = new_id;
		Genre_ID = new_id;
	}
	std::string Get_name() {
		return m_name;
	}
	void Set_name(std::string name) {
		m_name = name;
	}
	int Get_ID() {
		return m_id;
	}
	std::string Get_table_name() {
		return "Genre";
	}
};

class MovieGenre {
	static int MovieGenre_ID;
	int m_id;
	std::string m_movie_id;
	std::string m_genre_id;
public:
	MovieGenre() {

	}
	void Change_ID(int new_id) {
		m_id = new_id;
		MovieGenre_ID = new_id;
	}
	MovieGenre(std::string movie_id, std::string genre_id) : m_movie_id(movie_id), m_genre_id(genre_id) {
		MovieGenre_ID++;
		m_id = MovieGenre_ID;
	}
	std::string Get_movie_id() {
		return m_movie_id;
	}
	void Set_movie_id(std::string movie_id) {
		m_movie_id = movie_id;
	}
	std::string Get_genre_id() {
		return m_genre_id;
	}
	void Set_genre_id(std::string genre_id) {
		m_genre_id = genre_id;
	}
	int Get_ID() {
		return m_id;
	}
	std::string Get_table_name() {
		return "MovieGenre";
	}
};

class Production {
	static int Production_ID;
	int m_id;
	std::string m_name;
	std::string m_country_id;
public:
	Production() {

	}
	Production(std::string name, std::string country_id) : m_name(name), m_country_id(country_id) {
		Production_ID++;
		m_id = Production_ID;
	}
	std::string Get_name() {
		return m_name;
	}
	void Change_ID(int new_id) {
		m_id = new_id;
		Production_ID = new_id;
	}
	void Set_name(std::string name) {
		m_name = name;
	}
	std::string Get_country_id() {
		return m_country_id;
	}
	void Set_country_id(std::string country_id) {
		m_country_id = country_id;
	}
	int Get_ID() {
		return m_id;
	}
	std::string Get_table_name() {
		return "Production";
	}
};

class Country {
private:
	std::string m_name;
	static int Country_ID;
	int m_id;
public:
	Country() {

	}
	void Change_ID(int new_id) {
		m_id = new_id;
		Country_ID = new_id;
	}
	Country(std::string name) : m_name(name) {
		Country_ID++;
		m_id = Country_ID;
	}
	std::string Get_name() {
		return m_name;
	}
	void Set_name(std::string name) {
		m_name = name;
	}
	int Get_ID() {
		return m_id;
	}
	std::string Get_table_name() {
		return "Country";
	}

};

class Director {
	int m_id;
	static int Director_ID;
	std::string m_name;
public:
	Director() {

	}
	void Change_ID(int new_id) {
		m_id = new_id;
		Director_ID = new_id;
	}
	Director(std::string name) : m_name(name) {
		Director_ID++;
		m_id = Director_ID;
	}
	std::string Get_name() {
		return m_name;
	}
	void Set_name(std::string name) {
		m_name = name;
	}
	int Get_ID() {
		return m_id;
	}
	std::string Get_table_name() {
		return "Director";
	}
};

class DirectorMovie {
	static int DirectorMovie_ID;
	int m_id;
	std::string m_movie_id;
	std::string m_director_id;
public:
	DirectorMovie() {

	}
	void Change_ID(int new_id) {
		m_id = new_id;
		DirectorMovie_ID = new_id;
	}
	DirectorMovie(std::string movie_id, std::string director_id) : m_movie_id(movie_id), m_director_id(director_id) {
		DirectorMovie_ID++;
		m_id = DirectorMovie_ID;
	}
	std::string Get_movie_id() {
		return m_movie_id;
	}
	void Set_movie_id(std::string movie_id) {
		m_movie_id = movie_id;
	}
	std::string Get_director_id() {
		return m_director_id;
	}
	void Set_director_id(std::string director_id) {
		m_director_id = director_id;
	}
	int Get_ID() {
		return m_id;
	}
	std::string Get_table_name() {
		return "DirectorMovie";
	}
};

#endif
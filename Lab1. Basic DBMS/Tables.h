#ifndef Tables_hpp
#define Tables_hpp

#include <string>
#include <map>

using namespace std;

class Movie {
private:
	string m_name;
	string m_duration;
	string m_rate;
	string m_year;
	string m_production_id;
	static int Movie_ID;
	int m_id;

public:
	Movie() {

	}
	Movie(string name, string duration, string rate, string year, string production_id) : m_name(name), m_duration(duration), m_rate(rate), m_year(year), m_production_id(production_id) {
		Movie_ID++;
		m_id = Movie_ID;
	}
	string Get_name() {
		return m_name;
	}
	void Set_name(string name) {
		m_name = name;
	}
	string Get_duration() {
		return m_duration;
	}
	void Set_duration(string duration) {
		m_duration = duration;
	}
	string Get_rate() {
		return m_rate;
	}
	void Set_rate(string rate) {
		m_rate = rate;
	}
	string Get_year() {
		return m_year;
	}
	void Set_year(string year) {
		m_year = year;
	}
	string Get_production_id() {
		return m_production_id;
	}
	void Set_production_id(string production_id) {
		m_production_id = production_id;
	}
	void Change_ID(int new_id) {
		m_id = new_id;
		Movie_ID = new_id;
	}
	int Get_ID() {
		return m_id;
	}
	string Get_table_name() {
		return "Movie";
	}
};

class Genre {
private:
	string m_name;
	static int Genre_ID;
	int m_id;

public:
	Genre() {

	}
	Genre(string name) : m_name(name) {
		Genre_ID++;
		m_id = Genre_ID;
	}
	void Change_ID(int new_id) {
		m_id = new_id;
		Genre_ID = new_id;
	}
	string Get_name() {
		return m_name;
	}
	void Set_name(string name) {
		m_name = name;
	}
	int Get_ID() {
		return m_id;
	}
	string Get_table_name() {
		return "Genre";
	}
};

class MovieGenre {
	static int MovieGenre_ID;
	int m_id;
	string m_movie_id;
	string m_genre_id;
public:
	MovieGenre() {

	}
	void Change_ID(int new_id) {
		m_id = new_id;
		MovieGenre_ID = new_id;
	}
	MovieGenre(string movie_id, string genre_id) : m_movie_id(movie_id), m_genre_id(genre_id) {
		MovieGenre_ID++;
		m_id = MovieGenre_ID;
	}
	string Get_movie_id() {
		return m_movie_id;
	}
	void Set_movie_id(string movie_id) {
		m_movie_id = movie_id;
	}
	string Get_genre_id() {
		return m_genre_id;
	}
	void Set_genre_id(string genre_id) {
		m_genre_id = genre_id;
	}
	int Get_ID() {
		return m_id;
	}
	string Get_table_name() {
		return "MovieGenre";
	}
};

class Production {
	static int Production_ID;
	int m_id;
	string m_name;
	string m_country_id;
public:
	Production() {

	}
	Production(string name, string country_id) : m_name(name), m_country_id(country_id) {
		Production_ID++;
		m_id = Production_ID;
	}
	string Get_name() {
		return m_name;
	}
	void Change_ID(int new_id) {
		m_id = new_id;
		Production_ID = new_id;
	}
	void Set_name(string name) {
		m_name = name;
	}
	string Get_country_id() {
		return m_country_id;
	}
	void Set_country_id(string country_id) {
		m_country_id = country_id;
	}
	int Get_ID() {
		return m_id;
	}
	string Get_table_name() {
		return "Production";
	}
};

class Country {
private:
	string m_name;
	static int Country_ID;
	int m_id;
public:
	Country() {

	}
	void Change_ID(int new_id) {
		m_id = new_id;
		Country_ID = new_id;
	}
	Country(string name) : m_name(name) {
		Country_ID++;
		m_id = Country_ID;
	}
	string Get_name() {
		return m_name;
	}
	void Set_name(string name) {
		m_name = name;
	}
	int Get_ID() {
		return m_id;
	}
	string Get_table_name() {
		return "Country";
	}

};

class Director {
	int m_id;
	static int Director_ID;
	string m_name;
public:
	Director() {

	}
	void Change_ID(int new_id) {
		m_id = new_id;
		Director_ID = new_id;
	}
	Director(string name) : m_name(name) {
		Director_ID++;
		m_id = Director_ID;
	}
	string Get_name() {
		return m_name;
	}
	void Set_name(string name) {
		m_name = name;
	}
	int Get_ID() {
		return m_id;
	}
	string Get_table_name() {
		return "Director";
	}
};

class DirectorMovie {
	static int DirectorMovie_ID;
	int m_id;
	string m_movie_id;
	string m_director_id;
public:
	DirectorMovie() {

	}
	void Change_ID(int new_id) {
		m_id = new_id;
		DirectorMovie_ID = new_id;
	}
	DirectorMovie(string movie_id, string director_id) : m_movie_id(movie_id), m_director_id(director_id) {
		DirectorMovie_ID++;
		m_id = DirectorMovie_ID;
	}
	string Get_movie_id() {
		return m_movie_id;
	}
	void Set_movie_id(string movie_id) {
		m_movie_id = movie_id;
	}
	string Get_director_id() {
		return m_director_id;
	}
	void Set_director_id(string director_id) {
		m_director_id = director_id;
	}
	int Get_ID() {
		return m_id;
	}
	string Get_table_name() {
		return "DirectorMovie";
	}
};

#endif
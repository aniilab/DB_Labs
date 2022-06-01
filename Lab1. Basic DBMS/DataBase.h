#ifndef DataBase_hpp
#define DataBase_hpp

#include "DataPlace.h"
#include "Tables.h"
#include <memory>
using namespace std;

class DataBase {
public:
    DataBase();
    shared_ptr<DataPlace<Movie>> Get_movie_db();
    shared_ptr<DataPlace<Genre>> Get_genre_db();
    shared_ptr<DataPlace<MovieGenre>> Get_moviegenre_db();
    shared_ptr<DataPlace<Production>> Get_production_db();
    shared_ptr<DataPlace<Country>> Get_country_db();
    shared_ptr<DataPlace<Director>> Get_director_db();
    shared_ptr<DataPlace<DirectorMovie>> Get_directormovie_db();
    ~DataBase();
private:
    string Parse_stick(string& line);
    void Open_file(string line);
    shared_ptr<DataPlace<Movie>> movie_db;
    shared_ptr<DataPlace<Genre>> genre_db;
    shared_ptr<DataPlace<MovieGenre>> moviegenre_db;
    shared_ptr<DataPlace<Production>> production_db;
    shared_ptr<DataPlace<Country>> country_db;
    shared_ptr<DataPlace<Director>> director_db;
    shared_ptr<DataPlace<DirectorMovie>> directormovie_db;
};

#endif
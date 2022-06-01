#ifndef DataBase_h
#define DataBase_h

#include "DataPlace.h"
#include "Tables.h"
#include <memory>

class DataBase {
public:
    DataBase();
    std::shared_ptr<DataPlace<Movie>> Get_movie_db();
    std::shared_ptr<DataPlace<Genre>> Get_genre_db();
    std::shared_ptr<DataPlace<MovieGenre>> Get_moviegenre_db();
    std::shared_ptr<DataPlace<Production>> Get_production_db();
    std::shared_ptr<DataPlace<Country>> Get_country_db();
    std::shared_ptr<DataPlace<Director>> Get_director_db();
    std::shared_ptr<DataPlace<DirectorMovie>> Get_directormovie_db();
    ~DataBase();
private:
    std::string Parse_stick(std::string& line);
    void Open_file(std::string line);
    std::shared_ptr<DataPlace<Movie>> movie_db;
    std::shared_ptr<DataPlace<Genre>> genre_db;
    std::shared_ptr<DataPlace<MovieGenre>> moviegenre_db;
    std::shared_ptr<DataPlace<Production>> production_db;
    std::shared_ptr<DataPlace<Country>> country_db;
    std::shared_ptr<DataPlace<Director>> director_db;
    std::shared_ptr<DataPlace<DirectorMovie>> directormovie_db;
};

#endif
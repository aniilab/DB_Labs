#include "DataBase.h"

DataBase::DataBase() {
    movie_db = std::make_shared<DataPlace<Movie>>();
    genre_db = std::make_shared<DataPlace<Genre>>();
    moviegenre_db = std::make_shared<DataPlace<MovieGenre>>();
    production_db = std::make_shared<DataPlace<Production>>();
    country_db = std::make_shared<DataPlace<Country>>();
    director_db = std::make_shared<DataPlace<Director>>();
    directormovie_db = std::make_shared<DataPlace<DirectorMovie>>();

    std::string line;
    std::ifstream file("D:\c#\Lab1DB\result.txt");
    if (file.is_open()) {
        while (file) {
            std::getline(file, line);
            Open_file(line);
        }
    }
}

std::string DataBase::Parse_stick(std::string& line) {
    std::string result;
    auto stick_iter = std::find(line.begin(), line.end(), '|');
    if (stick_iter == line.end()) {
        return line;
    }
    else {
        result = std::string(line.begin(), stick_iter);
        line.erase(line.begin(), stick_iter + 1);
    }
    return result;
}

void DataBase::Open_file(std::string line) {
    std::string table = Parse_stick(line);
    if (table == "MOVIE") {
        auto id = Parse_stick(line);
        auto el = std::make_shared<Movie>(Parse_stick(line), Parse_stick(line), Parse_stick(line), Parse_stick(line), (Parse_stick(line)));
        if (el->Get_ID() != std::stoi(id)) {
            el->Change_ID(std::stoi(id));
        }
        movie_db->Save(el);
    }
    else if (table == "GENRE") {
        auto id = Parse_stick(line);
        auto el = std::make_shared<Genre>(Parse_stick(line));
        if (el->Get_ID() != std::stoi(id)) {
            el->Change_ID(std::stoi(id));
        }
        genre_db->Save(el);
    }
    else if (table == "MOVIEGENRE") {
        auto id = Parse_stick(line);
        auto el = std::make_shared<MovieGenre>(Parse_stick(line), Parse_stick(line));
        if (el->Get_ID() != std::stoi(id)) {
            el->Change_ID(std::stoi(id));
        }
        moviegenre_db->Save(el);
    }
    else if (table == "PRODUCTION") {
        auto id = Parse_stick(line);
        auto el = std::make_shared<Production>(Parse_stick(line), Parse_stick(line));
        if (el->Get_ID() != std::stoi(id)) {
            el->Change_ID(std::stoi(id));
        }
        production_db->Save(el);
    }
    else if (table == "COUNTRY") {
        auto id = Parse_stick(line);
        auto el = std::make_shared<Country>(Parse_stick(line));
        if (el->Get_ID() != std::stoi(id)) {
            el->Change_ID(std::stoi(id));
        }
        country_db->Save(el);
    }
    else if (table == "DIRECTOR") {
        auto id = Parse_stick(line);
        auto el = std::make_shared<Director>(Parse_stick(line));
        if (el->Get_ID() != std::stoi(id)) {
            el->Change_ID(std::stoi(id));
        }
        director_db->Save(el);
    }
    else if (table == "DIRECTORMOVIE") {
        auto id = Parse_stick(line);
        auto el = std::make_shared<DirectorMovie>(Parse_stick(line), Parse_stick(line));
        if (el->Get_ID() != std::stoi(id)) {
            el->Change_ID(std::stoi(id));
        }
        directormovie_db->Save(el);
    }
}
std::shared_ptr<DataPlace<Movie>> DataBase::Get_movie_db() {
    return movie_db;
}
std::shared_ptr<DataPlace<Genre>> DataBase::Get_genre_db() {
    return genre_db;
}
std::shared_ptr<DataPlace<MovieGenre>> DataBase::Get_moviegenre_db() {
    return moviegenre_db;
}
std::shared_ptr<DataPlace<Production>> DataBase::Get_production_db() {
    return production_db;
}
std::shared_ptr<DataPlace<Country>> DataBase::Get_country_db() {
    return country_db;
}
std::shared_ptr<DataPlace<Director>> DataBase::Get_director_db() {
    return director_db;
}
std::shared_ptr<DataPlace<DirectorMovie>> DataBase::Get_directormovie_db() {
    return directormovie_db;
}


DataBase::~DataBase() {
    std::ofstream file;
    file.open("D:\c#\Lab1DB\result.txt");
    if (file.is_open()) {
        for (auto i : movie_db->m_data) {
            file << "MOVIE|";
            file << i.second->Get_ID() << "|" << i.second->Get_name() << "|" << i.second->Get_duration() << "|" << i.second->Get_rate() << "|" <<
                i.second->Get_year() << "|" << i.second->Get_production_id() << "\n";
        }
        for (auto i : genre_db->m_data) {
            file << "GENRE|";
            file << i.second->Get_ID() << "|" << i.second->Get_name() << "\n";
        }
        for (auto i : moviegenre_db->m_data) {
            file << "MOVIEGENRE|";
            file << i.second->Get_ID() << "|" << i.second->Get_genre_id() << "|" << i.second->Get_movie_id() << "\n";
        }
        for (auto i : production_db->m_data) {
            file << "PRODUCTION|";
            file << i.second->Get_ID() << "|" << i.second->Get_name() << "|" << i.second->Get_country_id() << "\n";
        }
        for (auto i : country_db->m_data) {
            file << "COUNTRY|";
            file << i.second->Get_ID() << "|" << i.second->Get_name() << "\n";
        }
        for (auto i : director_db->m_data) {
            file << "DIRECTOR|";
            file << i.second->Get_ID() << "|" << i.second->Get_name() << "\n";
        }
        for (auto i : directormovie_db->m_data) {
            file << "DIRECTORMOVIE|";
            file << i.second->Get_ID() << "|" << i.second->Get_director_id() << "|" << i.second->Get_movie_id() << "\n";
        }

        file.close();
        std::cout << "Saved!\n";
    }
    else {
        std::cout << "Error while reading savings!\n";
    }
}
#include "Tools.h"

using namespace std;

Tools::Tools() {
    m_db.release();
    m_db = std::make_unique<DataBase>();
}

void Tools::Delete(std::string table_name, std::vector<std::string> args) {
    int ID;
    try {
        ID = std::stoi(args[0]);
    }
    catch (...) {
        throw std::logic_error("Invalid ID");
    }
    if (table_name == "MOVIE") {
        try {
            m_db->Get_movie_db()->Delete(ID);
        }
        catch (...) {
            throw std::runtime_error("Cannot delete!");
        }
    }
    else if (table_name == "GENRE") {
        try {
            m_db->Get_genre_db()->Delete(ID);
        }
        catch (...) {
            throw std::runtime_error("Cannot delete!");
        }
    }
    else if (table_name == "MOVIEGENRE") {
        try {
            m_db->Get_moviegenre_db()->Delete(ID);
        }
        catch (...) {
            throw std::runtime_error("Cannot delete!");
        }
    }
    else if (table_name == "PRODUCTION") {
        try {
            m_db->Get_production_db()->Delete(ID);
        }
        catch (...) {
            throw std::runtime_error("Cannot delete!");
        }
    }
    else if (table_name == "COUNTRY") {
        try {
            m_db->Get_country_db()->Delete(ID);
        }
        catch (...) {
            throw std::runtime_error("Cannot delete!");
        }
    }
    else if (table_name == "DIRECTOR") {
        try {
            m_db->Get_director_db()->Delete(ID);
        }
        catch (...) {
            throw std::runtime_error("Cannot delete!");
        }
    }
    else if (table_name == "DIRECTORMOVIE") {
        try {
            m_db->Get_directormovie_db()->Delete(ID);
        }
        catch (...) {
            throw std::runtime_error("Cannot delete!");
        }
    }
    else {
        std::cout << "Unknown table!\n";
    }
}

bool Tools::Add_m(std::string table_name, std::vector<std::string> args) {
    if (table_name == "MOVIE") {
        if (args.size() != 5) {
            throw std::runtime_error("Not enough args");
            return false;
        }
        else {
            m_db->Get_movie_db()->Save(std::make_shared<Movie>(args[0], args[1], args[2], args[3], args[4]));
            return true;
        }
    }
    else if (table_name == "GENRE") {
        if (args.size() != 1) {
            throw std::runtime_error("Not enough args");
            return false;
        }
        else {
            m_db->Get_genre_db()->Save(std::make_shared<Genre>(args[0]));
            return true;
        }
    }
    else if (table_name == "MOVIEGENRE") {
        if (args.size() != 2) {
            throw std::runtime_error("Not enough args");
            return false;
        }
        else {
            m_db->Get_moviegenre_db()->Save(std::make_shared<MovieGenre>(args[0], args[1]));
            return true;
        }
    }
    else if (table_name == "PRODUCTION") {
        if (args.size() != 2) {
            throw std::runtime_error("Not enough args");
            return false;
        }
        else {
            m_db->Get_production_db()->Save(std::make_shared<Production>(args[0], args[1]));
            return true;
        }
    }
    else if (table_name == "COUNTRY") {
        if (args.size() != 1) {
            throw std::runtime_error("Not enough args");
            return false;
        }
        else {
            m_db->Get_country_db()->Save(std::make_shared<Country>(args[0]));
            return true;
        }
    }
    else if (table_name == "DIRECTOR") {
        if (args.size() != 1) {
            throw std::runtime_error("Not enough args");
            return false;
        }
        else {
            m_db->Get_director_db()->Save(std::make_shared<Director>(args[0]));
            return true;
        }
    }
    else if (table_name == "DIRECTORMOVIE") {
        if (args.size() != 2) {
            throw std::runtime_error("Not enough args");
            return false;
        }
        else {
            m_db->Get_directormovie_db()->Save(std::make_shared<DirectorMovie>(args[0], args[1]));
            return true;
        }
    }
    else {
        throw std::runtime_error("Unknown table");
        return false;
    }
}

void Tools::Get_m(std::string table_name, std::string id) {
    int ID;
    try {
        ID = std::stoi(id);
    }
    catch (...) {
        throw std::runtime_error("Invalid ID");
    }
    if (table_name == "MOVIE") {
        auto el = m_db->Get_movie_db()->Get(ID);
        std::cout << "---Movie-" << el->Get_ID() << "---\n" << "Name:\t" << el->Get_name() << "\nDuration:\t" << el->Get_duration() << "\nIMDb rate:\t" << el->Get_rate() << "\nYear:\t" << el->Get_year() << "\nProduction ID:\t" << el->Get_production_id() << std::endl;
    }
    else if (table_name == "GENRE") {
        auto el = m_db->Get_genre_db()->Get(ID);
        std::cout << "---Genre-" << el->Get_ID() << "---\n" << "Name:\t" << el->Get_name() << std::endl;
    }
    else if (table_name == "MOVIEGENRE") {
        auto el = m_db->Get_moviegenre_db()->Get(ID);
        std::cout << "---MovieGenre-" << el->Get_ID() << "---\n" << "Movie ID:\t" << el->Get_movie_id() << "\nGenre ID:\t" << el->Get_genre_id() << std::endl;
    }
    else if (table_name == "PRODUCTION") {
        auto el = m_db->Get_production_db()->Get(ID);
        std::cout << "---Production-" << el->Get_ID() << "---\n" << "Name:\t" << el->Get_name() << "\nCountry ID:\t" << el->Get_country_id() << std::endl;
    }
    else if (table_name == "COUNTRY") {
        auto el = m_db->Get_country_db()->Get(ID);
        std::cout << "---Country-" << el->Get_ID() << "---\n" << "Country name:\t" << el->Get_name() << std::endl;
    }
    else if (table_name == "DIRECTOR") {
        auto el = m_db->Get_director_db()->Get(ID);
        std::cout << "---Director-" << el->Get_ID() << "---\n" << "Director name:\t" << el->Get_name() << std::endl;
    }
    else if (table_name == "DIRECTORMOVIE") {
        auto el = m_db->Get_directormovie_db()->Get(ID);
        std::cout << "---DirectorMovie-" << el->Get_ID() << "---\n" << "Movie ID:\t" << el->Get_movie_id() << "\nDirector ID:\t" << el->Get_director_id() << std::endl;
    }
    else {
        throw std::runtime_error("Unknown table");
    }
}

void Tools::Get_s(std::string table_name, std::vector<std::string> fields) {
    std::string ID;
    int id;
    try {
        ID = fields[0];
        id = std::stoi(ID);
        fields.erase(fields.begin());
    }
    catch (...) {
        throw std::runtime_error("Unknown id");
    }
    if (table_name == "MOVIE") {
        auto el = m_db->Get_movie_db()->Get(id);
        if (fields.size() == 0) {
            std::cout << "Put args (NAME, DURATION, RATE, YEAR, PRODUCTION_ID):\n> ";
            std::string allwords;
            std::getline(std::cin, allwords);
            std::string word;
            std::istringstream iss(allwords);
            while (iss >> word) { fields.push_back(word); }
        }
        for (auto field : fields) {
            if (field == "NAME") {
                std::cout << el->Get_name() << std::endl;
            }
            else if (field == "DURATION") {
                std::cout << el->Get_duration() << std::endl;
            }
            else if (field == "RATE") {
                std::cout << el->Get_rate() << std::endl;
            }
            else if (field == "YEAR") {
                std::cout << el->Get_year() << std::endl;
            }
            else if (field == "PRODUCTION_ID") {
                std::cout << el->Get_production_id() << std::endl;
            }
            else {
                std::cout << "Unknown field " << field << std::endl;
            }
        }
    }
    else if (table_name == "GENRE") {
        auto el = m_db->Get_genre_db()->Get(id);
        if (fields.size() == 0) {
            std::cout << "Put args (NAME:\n> ";
            std::string allwords;
            std::getline(std::cin, allwords);
            std::string word;
            std::istringstream iss(allwords);
            while (iss >> word) { fields.push_back(word); }
        }
        for (auto field : fields) {
            if (field == "NAME") {
                std::cout << el->Get_name() << std::endl;
            }
            else {
                std::cout << "Unknown field " << field << std::endl;
            }
        }
    }
    else if (table_name == "MOVIEGENRE") {
        auto el = m_db->Get_moviegenre_db()->Get(id);
        if (fields.size() == 0) {
            std::cout << "Put args (MOVIE_ID, GENRE_ID):\n> ";
            std::string allwords;
            std::getline(std::cin, allwords);
            std::string word;
            std::istringstream iss(allwords);
            while (iss >> word) { fields.push_back(word); }
        }
        for (auto field : fields) {
            if (field == "MOVIE_ID") {
                std::cout << el->Get_movie_id() << std::endl;
            }
            else if (field == "GENRE_ID") {
                std::cout << el->Get_genre_id() << std::endl;
            }
            else {
                std::cout << "Unknown field " << field << std::endl;
            }
        }
    }
    else if (table_name == "PRODUCTION") {
        auto el = m_db->Get_production_db()->Get(id);
        if (fields.size() == 0) {
            std::cout << "Put args (NAME, COUNTRY_ID):\n> ";
            std::string allwords;
            std::getline(std::cin, allwords);
            std::string word;
            std::istringstream iss(allwords);
            while (iss >> word) { fields.push_back(word); }
        }
        for (auto field : fields) {
            if (field == "NAME") {
                std::cout << el->Get_name() << std::endl;
            }
            else if (field == "COUNTRY_ID") {
                std::cout << el->Get_country_id() << std::endl;
            }
            else {
                std::cout << "Unknown field " << field << std::endl;
            }
        }
    }
    else if (table_name == "COUNTRY") {
        if (fields.size() == 0) {
            std::cout << "Put args (NAME):\n> ";
            std::string allwords;
            std::getline(std::cin, allwords);
            std::string word;
            std::istringstream iss(allwords);
            while (iss >> word) { fields.push_back(word); }
        }
        auto el = m_db->Get_country_db()->Get(id);
        for (auto field : fields) {
            if (field == "NAME") {
                std::cout << el->Get_name() << std::endl;
            }
            else {
                std::cout << "Unknown field " << field << std::endl;
            }
        }
    }
    else if (table_name == "DIRECTOR") {
        auto el = m_db->Get_director_db()->Get(id);
        if (fields.size() == 0) {
            std::cout << "Put args (NAME):\n> ";
            std::string allwords;
            std::getline(std::cin, allwords);
            std::string word;
            std::istringstream iss(allwords);
            while (iss >> word) { fields.push_back(word); }
        }
        for (auto field : fields) {
            if (field == "NAME") {
                std::cout << el->Get_name() << std::endl;
            }
            else {
                std::cout << "Unknown field " << field << std::endl;
            }
        }
    }
    else if (table_name == "DIRECTORMOVIE") {
        if (fields.size() == 0) {
            std::cout << "Put args (MOVIE_ID, DIRECTOR_ID):\n> ";
            std::string allwords;
            std::getline(std::cin, allwords);
            std::string word;
            std::istringstream iss(allwords);
            while (iss >> word) { fields.push_back(word); }
        }
        auto el = m_db->Get_directormovie_db()->Get(id);
        for (auto field : fields) {
            if (field == "MOVIE_ID") {
                std::cout << el->Get_movie_id() << std::endl;
            }
            else if (field == "DIRECTOR_ID") {
                std::cout << el->Get_director_id() << std::endl;
            }
            else {
                std::cout << "Unknown field " << field << std::endl;
            }
        }
    }
    else {
        throw std::runtime_error("Unknown table");
    }
}


void Tools::Update(std::string table_name, std::vector<std::string> args) {
    if (args.size() != 3) {
        throw std::logic_error("Not enough arguments!");
    }
    int id;
    try {
        id = std::stoi(args[0]);
    }
    catch (...) {
        throw std::runtime_error("Invalid argument!");
    }
    if (table_name == "MOVIE") {
        auto movies_db = m_db->Get_movie_db();
        std::shared_ptr<Movie> el;
        try {
            el = movies_db->Get(id);
        }
        catch (...) {
            throw std::runtime_error("Invalid ID");
        }
        if (args[1] == "NAME") {
            try {
                el->Set_name(args[2]);
                std::cout << "Done!\n";
            }
            catch (...) {
                std::runtime_error("Setting error!");
            }
        }
        else if (args[1] == "DURATION") {
            try {
                el->Set_duration(args[2]);
                std::cout << "Done!\n";
            }
            catch (...) {
                std::runtime_error("Setting error!");
            }
        }
        else if (args[1] == "RATE") {
            try {
                el->Set_rate(args[2]);
                std::cout << "Done!\n";
            }
            catch (...) {
                std::runtime_error("Setting error!");
            }
        }
        else if (args[1] == "YEAR") {
            try {
                el->Set_year(args[2]);
                std::cout << "Done!\n";
            }
            catch (...) {
                std::runtime_error("Setting error!");
            }
        }
        else if (args[1] == "PRODUCTION_ID") {
            try {
                el->Set_production_id(args[2]);
                std::cout << "Done!\n";
            }
            catch (...) {
                std::runtime_error("Setting error!");
            }
        }
        else {
            throw std::logic_error("Invalid param!\nTry NAME/DURATION/RATE/YEAR/PRODUCTION_ID/\n");
        }
        return;
    }
    else if (table_name == "GENRE") {
        auto genres_db = m_db->Get_genre_db();
        std::shared_ptr<Genre> el;
        try {
            el = genres_db->Get(id);
        }
        catch (...) {
            throw std::runtime_error("Invalid ID");
        }
        if (args[1] == "NAME") {
            try {
                el->Set_name(args[2]);
                std::cout << "Done!\n";
            }
            catch (...) {
                std::runtime_error("Setting error!");
            }
        }
        else {
            throw std::logic_error("Invalid param!\nTry NAME\n");
        }
        return;
    }
    else if (table_name == "MOVIEGENRE") {
        auto moviegenre_db = m_db->Get_moviegenre_db();
        std::shared_ptr<MovieGenre> el;
        try {
            el = moviegenre_db->Get(id);
        }
        catch (...) {
            throw std::runtime_error("Invalid ID");
        }
        if (args[1] == "MOVIE_ID") {
            try {
                el->Set_movie_id(args[2]);
                std::cout << "Done!\n";
            }
            catch (...) {
                std::runtime_error("Setting error!");
            }
        }
        else if (args[1] == "GENRE_ID") {
            try {
                el->Set_genre_id(args[2]);
                std::cout << "Done!\n";
            }
            catch (...) {
                std::runtime_error("Setting error!");
            }
        }
        else {
            throw std::logic_error("Invalid param!\nTry MOVIE_ID/GENRE_ID/\n");
        }
        return;
    }
    else if (table_name == "PRODUCTION") {
        auto own_db = m_db->Get_production_db();
        std::shared_ptr<Production> el;
        try {
            el = own_db->Get(id);
        }
        catch (...) {
            throw std::runtime_error("Invalid ID");
        }
        if (args[1] == "NAME") {
            try {
                el->Set_name(args[2]);
                std::cout << "Done!\n";
            }
            catch (...) {
                std::runtime_error("Setting error!");
            }
        }
        else if (args[1] == "COUNTRY_ID") {
            try {
                el->Set_country_id(args[2]);
                std::cout << "Done!\n";
            }
            catch (...) {
                std::runtime_error("Setting error!");
            }
        }
        else {
            throw std::logic_error("Invalid param!\nTry NAME/COUNTRY_ID\n");
        }
        return;
    }
    else if (table_name == "COUNTRY") {
        auto country_db = m_db->Get_country_db();
        std::shared_ptr<Country> el;
        try {
            el = country_db->Get(id);
        }
        catch (...) {
            throw std::runtime_error("Invalid ID");
        }
        if (args[1] == "NAME") {
            try {
                el->Set_name(args[2]);
                std::cout << "Done!\n";
            }
            catch (...) {
                std::runtime_error("Setting error!");
            }
        }
        else {
            throw std::logic_error("Invalid param!\nTry NAME\n");
        }
        return;
    }
    else if (table_name == "DIRECTOR") {
        auto director_db = m_db->Get_director_db();
        std::shared_ptr<Director> el;
        try {
            el = director_db->Get(id);
        }
        catch (...) {
            throw std::runtime_error("Invalid ID");
        }
        if (args[1] == "NAME") {
            try {
                el->Set_name(args[2]);
                std::cout << "Done!\n";
            }
            catch (...) {
                std::runtime_error("Setting error!");
            }
        }
        else {
            throw std::logic_error("Invalid param!\nTry NAME\n");
        }
        return;
    }
    if (table_name == "DIRECTORMOVIE") {
        auto directormovie_db = m_db->Get_directormovie_db();
        std::shared_ptr<DirectorMovie> el;
        try {
            el = directormovie_db->Get(id);
        }
        catch (...) {
            throw std::runtime_error("Invalid ID");
        }
        if (args[1] == "MOVIE_ID") {
            try {
                el->Set_movie_id(args[2]);
                std::cout << "Done!\n";
            }
            catch (...) {
                std::runtime_error("Setting error!");
            }
        }
        else if (args[1] == "DIRECTOR_ID") {
            try {
                el->Set_director_id(args[2]);
                std::cout << "Done!\n";
            }
            catch (...) {
                std::runtime_error("Setting error!");
            }
        }
        else {
            throw std::logic_error("Invalid param!\nTry MOVIE_ID/DIRECTOR_ID\n");
        }
        return;
    }
    else {
        throw std::logic_error("Unknown table!\nTry MOVIE/GENRE/MOVIEGENRE/PRODUCTION/COUNTRY/DIRECTOR/DIRECTORMOVIE\n");
    }
}
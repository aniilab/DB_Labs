#include "Tools.h"

using namespace std;

Tools::Tools() {
    m_db.release();
    m_db = make_unique<DataBase>();
}

void Tools::Delete(string table_name, vector<string> args) {
    int ID;
    try {
        ID = stoi(args[0]);
    }
    catch (...) {
        throw logic_error("Invalid ID");
    }
    if (table_name == "MOVIE") {
        try {
            m_db->Get_movie_db()->Delete(ID);
        }
        catch (...) {
            throw runtime_error("Cannot delete!");
        }
    }
    else if (table_name == "GENRE") {
        try {
            m_db->Get_genre_db()->Delete(ID);
        }
        catch (...) {
            throw runtime_error("Cannot delete!");
        }
    }
    else if (table_name == "MOVIEGENRE") {
        try {
            m_db->Get_moviegenre_db()->Delete(ID);
        }
        catch (...) {
            throw runtime_error("Cannot delete!");
        }
    }
    else if (table_name == "PRODUCTION") {
        try {
            m_db->Get_production_db()->Delete(ID);
        }
        catch (...) {
            throw runtime_error("Cannot delete!");
        }
    }
    else if (table_name == "COUNTRY") {
        try {
            m_db->Get_country_db()->Delete(ID);
        }
        catch (...) {
            throw runtime_error("Cannot delete!");
        }
    }
    else if (table_name == "DIRECTOR") {
        try {
            m_db->Get_director_db()->Delete(ID);
        }
        catch (...) {
            throw runtime_error("Cannot delete!");
        }
    }
    else if (table_name == "DIRECTORMOVIE") {
        try {
            m_db->Get_directormovie_db()->Delete(ID);
        }
        catch (...) {
            throw runtime_error("Cannot delete!");
        }
    }
    else {
        cout << "Unknown table!\n";
    }
}

bool Tools::Add_m(string table_name, vector<string> args) {
    if (table_name == "MOVIE") {
        if (args.size() != 5) {
            throw runtime_error("Not enough args");
            return false;
        }
        else {
            m_db->Get_movie_db()->Save(make_shared<Movie>(args[0], args[1], args[2], args[3], args[4]));
            return true;
        }
    }
    else if (table_name == "GENRE") {
        if (args.size() != 1) {
            throw runtime_error("Not enough args");
            return false;
        }
        else {
            m_db->Get_genre_db()->Save(make_shared<Genre>(args[0]));
            return true;
        }
    }
    else if (table_name == "MOVIEGENRE") {
        if (args.size() != 2) {
            throw runtime_error("Not enough args");
            return false;
        }
        else {
            m_db->Get_moviegenre_db()->Save(make_shared<MovieGenre>(args[0], args[1]));
            return true;
        }
    }
    else if (table_name == "PRODUCTION") {
        if (args.size() != 2) {
            throw runtime_error("Not enough args");
            return false;
        }
        else {
            m_db->Get_production_db()->Save(make_shared<Production>(args[0], args[1]));
            return true;
        }
    }
    else if (table_name == "COUNTRY") {
        if (args.size() != 1) {
            throw runtime_error("Not enough args");
            return false;
        }
        else {
            m_db->Get_country_db()->Save(make_shared<Country>(args[0]));
            return true;
        }
    }
    else if (table_name == "DIRECTOR") {
        if (args.size() != 1) {
            throw runtime_error("Not enough args");
            return false;
        }
        else {
            m_db->Get_director_db()->Save(make_shared<Director>(args[0]));
            return true;
        }
    }
    else if (table_name == "DIRECTORMOVIE") {
        if (args.size() != 2) {
            throw runtime_error("Not enough args");
            return false;
        }
        else {
            m_db->Get_directormovie_db()->Save(make_shared<DirectorMovie>(args[0], args[1]));
            return true;
        }
    }
    else {
        throw runtime_error("Unknown table");
        return false;
    }
}

void Tools::Get_m(string table_name, string id) {
    int ID;
    try {
        ID = stoi(id);
    }
    catch (...) {
        throw runtime_error("Invalid ID");
    }
    if (table_name == "MOVIE") {
        auto el = m_db->Get_movie_db()->Get(ID);
        cout << "---Movie-" << el->Get_ID() << "---\n" << "Name:\t" << el->Get_name() << "\nDuration:\t" << el->Get_duration() << "\nIMDb rate:\t" << el->Get_rate() << "\nYear:\t" << el->Get_year() << "\nProduction ID:\t" << el->Get_production_id() << endl;
    }
    else if (table_name == "GENRE") {
        auto el = m_db->Get_genre_db()->Get(ID);
        cout << "---Genre-" << el->Get_ID() << "---\n" << "Name:\t" << el->Get_name() << endl;
    }
    else if (table_name == "MOVIEGENRE") {
        auto el = m_db->Get_moviegenre_db()->Get(ID);
        cout << "---MovieGenre-" << el->Get_ID() << "---\n" << "Movie ID:\t" << el->Get_movie_id() << "\nGenre ID:\t" << el->Get_genre_id() << endl;
    }
    else if (table_name == "PRODUCTION") {
        auto el = m_db->Get_production_db()->Get(ID);
        cout << "---Production-" << el->Get_ID() << "---\n" << "Name:\t" << el->Get_name() << "\nCountry ID:\t" << el->Get_country_id() << endl;
    }
    else if (table_name == "COUNTRY") {
        auto el = m_db->Get_country_db()->Get(ID);
        cout << "---Country-" << el->Get_ID() << "---\n" << "Country name:\t" << el->Get_name() << endl;
    }
    else if (table_name == "DIRECTOR") {
        auto el = m_db->Get_director_db()->Get(ID);
        cout << "---Director-" << el->Get_ID() << "---\n" << "Director name:\t" << el->Get_name() << endl;
    }
    else if (table_name == "DIRECTORMOVIE") {
        auto el = m_db->Get_directormovie_db()->Get(ID);
        cout << "---DirectorMovie-" << el->Get_ID() << "---\n" << "Movie ID:\t" << el->Get_movie_id() << "\nDirector ID:\t" << el->Get_director_id() << endl;
    }
    else {
        throw runtime_error("Unknown table");
    }
}

void Tools::Get_s(string table_name, vector<string> fields) {
    string ID;
    int id;
    try {
        ID = fields[0];
        id = stoi(ID);
        fields.erase(fields.begin());
    }
    catch (...) {
        throw runtime_error("Unknown id");
    }
    if (table_name == "MOVIE") {
        auto el = m_db->Get_movie_db()->Get(id);
        if (fields.size() == 0) {
            cout << "Put args (NAME, DURATION, RATE, YEAR, PRODUCTION_ID):\n> ";
            string allwords;
            getline(cin, allwords);
            string word;
            istringstream iss(allwords);
            while (iss >> word) { fields.push_back(word); }
        }
        for (auto field : fields) {
            if (field == "NAME") {
                cout << el->Get_name() << endl;
            }
            else if (field == "DURATION") {
                cout << el->Get_duration() << endl;
            }
            else if (field == "RATE") {
                cout << el->Get_rate() << endl;
            }
            else if (field == "YEAR") {
                cout << el->Get_year() << endl;
            }
            else if (field == "PRODUCTION_ID") {
                cout << el->Get_production_id() << endl;
            }
            else {
                cout << "Unknown field " << field << endl;
            }
        }
    }
    else if (table_name == "GENRE") {
        auto el = m_db->Get_genre_db()->Get(id);
        if (fields.size() == 0) {
            cout << "Put args (NAME:\n> ";
            string allwords;
            getline(cin, allwords);
            string word;
            istringstream iss(allwords);
            while (iss >> word) { fields.push_back(word); }
        }
        for (auto field : fields) {
            if (field == "NAME") {
                cout << el->Get_name() << endl;
            }
            else {
                cout << "Unknown field " << field << endl;
            }
        }
    }
    else if (table_name == "MOVIEGENRE") {
        auto el = m_db->Get_moviegenre_db()->Get(id);
        if (fields.size() == 0) {
            cout << "Put args (MOVIE_ID, GENRE_ID):\n> ";
            string allwords;
            getline(cin, allwords);
            string word;
            istringstream iss(allwords);
            while (iss >> word) { fields.push_back(word); }
        }
        for (auto field : fields) {
            if (field == "MOVIE_ID") {
                cout << el->Get_movie_id() << endl;
            }
            else if (field == "GENRE_ID") {
                cout << el->Get_genre_id() << endl;
            }
            else {
                cout << "Unknown field " << field << endl;
            }
        }
    }
    else if (table_name == "PRODUCTION") {
        auto el = m_db->Get_production_db()->Get(id);
        if (fields.size() == 0) {
            cout << "Put args (NAME, COUNTRY_ID):\n> ";
            string allwords;
            getline(cin, allwords);
            string word;
            istringstream iss(allwords);
            while (iss >> word) { fields.push_back(word); }
        }
        for (auto field : fields) {
            if (field == "NAME") {
                cout << el->Get_name() << endl;
            }
            else if (field == "COUNTRY_ID") {
                cout << el->Get_country_id() << endl;
            }
            else {
                cout << "Unknown field " << field << endl;
            }
        }
    }
    else if (table_name == "COUNTRY") {
        if (fields.size() == 0) {
            cout << "Put args (NAME):\n> ";
            string allwords;
            getline(cin, allwords);
            string word;
            istringstream iss(allwords);
            while (iss >> word) { fields.push_back(word); }
        }
        auto el = m_db->Get_country_db()->Get(id);
        for (auto field : fields) {
            if (field == "NAME") {
                cout << el->Get_name() << endl;
            }
            else {
                cout << "Unknown field " << field << endl;
            }
        }
    }
    else if (table_name == "DIRECTOR") {
        auto el = m_db->Get_director_db()->Get(id);
        if (fields.size() == 0) {
            cout << "Put args (NAME):\n> ";
            string allwords;
            getline(cin, allwords);
            string word;
            istringstream iss(allwords);
            while (iss >> word) { fields.push_back(word); }
        }
        for (auto field : fields) {
            if (field == "NAME") {
                cout << el->Get_name() << endl;
            }
            else {
                cout << "Unknown field " << field << endl;
            }
        }
    }
    else if (table_name == "DIRECTORMOVIE") {
        if (fields.size() == 0) {
            cout << "Put args (MOVIE_ID, DIRECTOR_ID):\n> ";
            string allwords;
            getline(cin, allwords);
            string word;
            istringstream iss(allwords);
            while (iss >> word) { fields.push_back(word); }
        }
        auto el = m_db->Get_directormovie_db()->Get(id);
        for (auto field : fields) {
            if (field == "MOVIE_ID") {
                cout << el->Get_movie_id() << endl;
            }
            else if (field == "DIRECTOR_ID") {
                cout << el->Get_director_id() << endl;
            }
            else {
                cout << "Unknown field " << field << endl;
            }
        }
    }
    else {
        throw runtime_error("Unknown table");
    }
}


void Tools::Update(string table_name, vector<string> args) {
    if (args.size() != 3) {
        throw logic_error("Not enough arguments!");
    }
    int id;
    try {
        id = stoi(args[0]);
    }
    catch (...) {
        throw runtime_error("Invalid argument!");
    }
    if (table_name == "MOVIE") {
        auto movies_db = m_db->Get_movie_db();
        shared_ptr<Movie> el;
        try {
            el = movies_db->Get(id);
        }
        catch (...) {
            throw runtime_error("Invalid ID");
        }
        if (args[1] == "NAME") {
            try {
                el->Set_name(args[2]);
                cout << "Done!\n";
            }
            catch (...) {
                runtime_error("Setting error!");
            }
        }
        else if (args[1] == "DURATION") {
            try {
                el->Set_duration(args[2]);
                cout << "Done!\n";
            }
            catch (...) {
                runtime_error("Setting error!");
            }
        }
        else if (args[1] == "RATE") {
            try {
                el->Set_rate(args[2]);
                cout << "Done!\n";
            }
            catch (...) {
                runtime_error("Setting error!");
            }
        }
        else if (args[1] == "YEAR") {
            try {
                el->Set_year(args[2]);
                cout << "Done!\n";
            }
            catch (...) {
                runtime_error("Setting error!");
            }
        }
        else if (args[1] == "PRODUCTION_ID") {
            try {
                el->Set_production_id(args[2]);
                cout << "Done!\n";
            }
            catch (...) {
                runtime_error("Setting error!");
            }
        }
        else {
            throw logic_error("Invalid param!\nTry NAME/DURATION/RATE/YEAR/PRODUCTION_ID/\n");
        }
        return;
    }
    else if (table_name == "GENRE") {
        auto production_db = m_db->Get_production_db();
        shared_ptr<Genre> el;
        try {
            el = production_db->Get(id);
        }
        catch (...) {
            throw runtime_error("Invalid ID");
        }
        if (args[1] == "NAME") {
            try {
                el->Set_name(args[2]);
                cout << "Done!\n";
            }
            catch (...) {
                runtime_error("Setting error!");
            }
        }
        else {
            throw logic_error("Invalid param!\nTry NAME\n");
        }
        return;
    }
    else if (table_name == "MOVIEGENRE") {
        auto moviegenre_db = m_db->Get_moviegenre_db();
        shared_ptr<MovieGenre> el;
        try {
            el = moviegenre_db->Get(id);
        }
        catch (...) {
            throw runtime_error("Invalid ID");
        }
        if (args[1] == "MOVIE_ID") {
            try {
                el->Set_movie_id(args[2]);
                cout << "Done!\n";
            }
            catch (...) {
                runtime_error("Setting error!");
            }
        }
        else if (args[1] == "GENRE_ID") {
            try {
                el->Set_genre_id(args[2]);
                cout << "Done!\n";
            }
            catch (...) {
                runtime_error("Setting error!");
            }
        }
        else {
            throw logic_error("Invalid param!\nTry MOVIE_ID/GENRE_ID/\n");
        }
        return;
    }
    else if (table_name == "PRODUCTION") {
        auto own_db = m_db->Get_production_db();
        shared_ptr<Production> el;
        try {
            el = own_db->Get(id);
        }
        catch (...) {
            throw runtime_error("Invalid ID");
        }
        if (args[1] == "NAME") {
            try {
                el->Set_name(args[2]);
                cout << "Done!\n";
            }
            catch (...) {
                runtime_error("Setting error!");
            }
        }
        else if (args[1] == "COUNTRY_ID") {
            try {
                el->Set_country_id(args[2]);
                cout << "Done!\n";
            }
            catch (...) {
                runtime_error("Setting error!");
            }
        }
        else {
            throw logic_error("Invalid param!\nTry NAME/COUNTRY_ID\n");
        }
        return;
    }
    else if (table_name == "COUNTRY") {
        auto country_db = m_db->Get_country_db();
        shared_ptr<Country> el;
        try {
            el = country_db->Get(id);
        }
        catch (...) {
            throw runtime_error("Invalid ID");
        }
        if (args[1] == "NAME") {
            try {
                el->Set_name(args[2]);
                cout << "Done!\n";
            }
            catch (...) {
                runtime_error("Setting error!");
            }
        }
        else {
            throw logic_error("Invalid param!\nTry NAME\n");
        }
        return;
    }
    else if (table_name == "DIRECTOR") {
        auto director_db = m_db->Get_director_db();
        shared_ptr<Director> el;
        try {
            el = director_db->Get(id);
        }
        catch (...) {
            throw runtime_error("Invalid ID");
        }
        if (args[1] == "NAME") {
            try {
                el->Set_name(args[2]);
                cout << "Done!\n";
            }
            catch (...) {
                runtime_error("Setting error!");
            }
        }
        else {
            throw logic_error("Invalid param!\nTry NAME\n");
        }
        return;
    }
    if (table_name == "DIRECTORMOVIE") {
        auto directormovie_db = m_db->Get_directormovie_db();
        shared_ptr<DirectorMovie> el;
        try {
            el = directormovie_db->Get(id);
        }
        catch (...) {
            throw runtime_error("Invalid ID");
        }
        if (args[1] == "MOVIE_ID") {
            try {
                el->Set_movie_id(args[2]);
                cout << "Done!\n";
            }
            catch (...) {
                runtime_error("Setting error!");
            }
        }
        else if (args[1] == "DIRECTOR_ID") {
            try {
                el->Set_director_id(args[2]);
                cout << "Done!\n";
            }
            catch (...) {
                runtime_error("Setting error!");
            }
        }
        else {
            throw logic_error("Invalid param!\nTry MOVIE_ID/DIRECTOR_ID\n");
        }
        return;
    }
    else {
        throw logic_error("Unknown table!\nTry MOVIE/GENRE/MOVIEGENRE/PRODUCTION/COUNTRY/DIRECTOR/DIRECTORMOVIE\n");
    }
}
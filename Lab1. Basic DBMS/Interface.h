#ifndef Interface_hpp
#define Interface_hpp

#include "Tools.h"
using namespace std;

class Interface {
public:
    Interface();
    bool Command_getter();
    void Parser();
    bool DoStaff();
private:
    const string BigHelpMessage = "Available commands: INSERT/UPDATE/GET-M/GET-S/DELETE/STOP\nTables: MOVIE, GENRE, MOVIEGENRE, PRODUCTION, COUNTRY, DIRECTOR, DIRECTORMOVIE\nIf you need to see attributes of a certain table use \"HELP table\"\nIf you need to see information about command use \"HELP command\"\n";
    const string Help_Insert = "Use \"INSERT TABLE_NAME arguments\" to add element to specific table";
    const string Help_Update = "Use \"UPDATE TABLE_NAME ID FIELD new_value\" to update field";
    const string Help_Get_m = "Use \"GET-M TABLE_NAME ID\" to see specific element";
    const string Help_Get_s = "Use \"GET-S TABLE_NAME ID FIELD_NAME\" to see the specific field of the element";
    const string Help_Delete = "Use \"DELETE TABLE_NAME ID\" to delete element";
    const string Help_Stop = "Use \"STOP\" to save database and quit";
    const string Help_Movie = "{name, duration, rate, year, production_id}";
    const string Help_Genre = "{name}";
    const string Help_MovieGenre = "{movie_id, genre_id}";
    const string Help_Production = "{name, country_id}";
    const string Help_Country = "{name}";
    const string Help_Director = "{name}";
    const string Help_DirectorMovie = "{movie_id, director_id}";
    unique_ptr<Tools> m_tools;
    string m_command;
    vector<string> m_tokens;
};


#endif 

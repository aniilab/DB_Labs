#ifndef Interface_h
#define Interface_h

#include "Tools.h"

class Interface {
public:
    Interface();
    bool Command_getter();
    void Parser();
    bool DoStaff();
private:
    const std::string BigHelpMessage = "Available commands: INSERT/UPDATE/GET-M/GET-S/DELETE/STOP\nTables: MOVIE, GENRE, MOVIEGENRE, PRODUCTION, COUNTRY, DIRECTOR, DIRECTORMOVIE\nIf you need to see attributes of a certain table use \"HELP table\"\nIf you need to see information about command use \"HELP command\"\n";
    const std::string Help_Insert = "Use \"INSERT TABLE_NAME arguments\" to add element to specific table";
    const std::string Help_Update = "Use \"UPDATE TABLE_NAME ID FIELD new_value\" to update field";
    const std::string Help_Get_m = "Use \"GET-M TABLE_NAME ID\" to see specific element";
    const std::string Help_Get_s = "Use \"GET-S TABLE_NAME ID FIELD_NAME\" to see the specific field of the element";
    const std::string Help_Delete = "Use \"DELETE TABLE_NAME ID\" to delete element";
    const std::string Help_Stop = "Use \"STOP\" to save database and quit";
    const std::string Help_Movie = "{name, duration, rate, year, production_id}";
    const std::string Help_Genre = "{name}";
    const std::string Help_MovieGenre = "{movie_id, genre_id}";
    const std::string Help_Production = "{name, country_id}";
    const std::string Help_Country = "{name}";
    const std::string Help_Director = "{name}";
    const std::string Help_DirectorMovie = "{movie_id, director_id}";
    std::unique_ptr<Tools> m_tools;
    std::string m_command;
    std::vector<std::string> m_tokens;
};


#endif 

#ifndef Tools_h
#define Tools_h

#include "DataBase.h"
#include <string>
#include <vector>
#include <sstream>
#include <stdexcept>

using namespace std;

class Tools {
public:
    Tools();
    bool Add_m(std::string table_name, std::vector<std::string> args);
    void Get_m(std::string table_name, std::string id);
    void Get_s(std::string table_name, std::vector<std::string> fields);
    void Update(std::string table_name, std::vector<std::string> args);
    void Delete(std::string table_name, std::vector<std::string> args);
private:
    std::unique_ptr<DataBase> m_db;
};

#endif
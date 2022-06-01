#ifndef Tools_hpp
#define Tools_hpp

#include "DataBase.h"
#include <string>
#include <vector>
#include <sstream>
#include <stdexcept>

using namespace std;

class Tools {
public:
    Tools();
    bool Add_m(string table_name, vector<string> args);
    void Get_m(string table_name, string id);
    void Get_s(string table_name, vector<string> fields);
    void Update(string table_name, vector<string> args);
    void Delete(string table_name, vector<string> args);
private:
    unique_ptr<DataBase> m_db;
};

#endif
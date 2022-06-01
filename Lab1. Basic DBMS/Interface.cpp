#include "Interface.h"
using namespace std;

Interface::Interface() {
    m_tools = make_unique<Tools>();
}

bool Interface::Command_getter() {
    cout << "- ";
    getline(cin, m_command);
    Parser();
    return DoStaff();
}

void Interface::Parser() {
    m_tokens = {};
    string token = "";
    for (int i = 0; i < m_command.length(); i++) {
        if (m_command[i] == ' ') {
            m_tokens.push_back(token);
            token = "";
        }
        else {
            token.push_back(m_command[i]);
        }
    }
    m_tokens.push_back(token);
}

bool Interface::DoStaff() {
    string what_to_do = m_tokens[0]; //command

    m_tokens.erase(m_tokens.begin());
    if (what_to_do == "STOP") {
        return false;
    }
    else if (what_to_do == "INSERT") {
        string table_name = m_tokens[0];
        m_tokens.erase(m_tokens.begin());

        try {
            m_tools->Add_m(table_name, m_tokens);
        }
        catch (exception& ex) {
            cout << "Error: " << ex.what() << endl;
        }
    }
    else if (what_to_do == "GET-M") {
        string table_name = m_tokens[0];
        try {
            m_tools->Get_m(table_name, m_tokens[1]);
        }
        catch (exception& ex) {
            cout << "Error: " << ex.what() << endl;
        }
    }
    else if (what_to_do == "GET-S") {
        string table_name = m_tokens[0];
        m_tokens.erase(m_tokens.begin());
        try {
            m_tools->Get_s(table_name, m_tokens);
        }
        catch (exception& ex) {
            cout << "Error: " << ex.what() << endl;
        }
    }
    else if (what_to_do == "DELETE") {
        string table_name = m_tokens[0];
        m_tokens.erase(m_tokens.begin());
        try {
            m_tools->Delete(table_name, m_tokens);
        }
        catch (exception& ex) {
            cout << "Error: " << ex.what() << endl;
        }
    }
    else if (what_to_do == "UPDATE") {
        string table_name = m_tokens[0];
        m_tokens.erase(m_tokens.begin());
        try {
            m_tools->Update(table_name, m_tokens);
        }
        catch (exception& ex) {
            cout << "Error: " << ex.what() << endl;
        }
    }
    else if (what_to_do == "HELP") {
        if (m_tokens.size() == 0) {
            cout << BigHelpMessage << endl;
        }
        else {
            if (m_tokens[0] == "MOVIE") cout << Help_Movie << endl;
            else if (m_tokens[0] == "GENRE") cout << Help_Genre << endl;
            else if (m_tokens[0] == "MOVIEGENRE") cout << Help_MovieGenre << endl;
            else if (m_tokens[0] == "PRODUCTION") cout << Help_Production << endl;
            else if (m_tokens[0] == "COUNTRY") cout << Help_Country << endl;
            else if (m_tokens[0] == "DIRECTOR") cout << Help_Director << endl;
            else if (m_tokens[0] == "DIRECTORMOVIE") cout << Help_DirectorMovie << endl;
            else if (m_tokens[0] == "GET-M") cout << Help_Get_m << endl;
            else if (m_tokens[0] == "GET-S") cout << Help_Get_s << endl;
            else if (m_tokens[0] == "INSERT") cout << Help_Insert << endl;
            else if (m_tokens[0] == "UPDATE") cout << Help_Update << endl;
            else if (m_tokens[0] == "DELETE") cout << Help_Delete << endl;
            else if (m_tokens[0] == "Stop") cout << Help_Stop << endl;
            else cout << "Unknown args!\n" << BigHelpMessage << endl;
        }
    }
    return true;
}
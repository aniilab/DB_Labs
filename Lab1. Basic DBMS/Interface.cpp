#include "Interface.h"

Interface::Interface() {
    m_tools = std::make_unique<Tools>();
}

bool Interface::Command_getter() {
    std::cout << "- ";
    std::getline(std::cin, m_command);
    Parser();
    return DoStaff();
}

void Interface::Parser() {
    m_tokens = {};
    std::string token = "";
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
    std::string what_to_do = m_tokens[0]; //command

    m_tokens.erase(m_tokens.begin());
    if (what_to_do == "STOP") {
        return false;
    }
    else if (what_to_do == "INSERT") {
        std::string table_name = m_tokens[0];
        m_tokens.erase(m_tokens.begin());

        try {
            m_tools->Add_m(table_name, m_tokens);
        }
        catch (std::exception& ex) {
            std::cout << "Error: " << ex.what() << std::endl;
        }
    }
    else if (what_to_do == "GET-M") {
        std::string table_name = m_tokens[0];
        try {
            m_tools->Get_m(table_name, m_tokens[1]);
        }
        catch (std::exception& ex) {
            std::cout << "Error: " << ex.what() << std::endl;
        }
    }
    else if (what_to_do == "GET-S") {
        std::string table_name = m_tokens[0];
        m_tokens.erase(m_tokens.begin());
        try {
            m_tools->Get_s(table_name, m_tokens);
        }
        catch (std::exception& ex) {
            std::cout << "Error: " << ex.what() << std::endl;
        }
    }
    else if (what_to_do == "DELETE") {
        std::string table_name = m_tokens[0];
        m_tokens.erase(m_tokens.begin());
        try {
            m_tools->Delete(table_name, m_tokens);
        }
        catch (std::exception& ex) {
            std::cout << "Error: " << ex.what() << std::endl;
        }
    }
    else if (what_to_do == "UPDATE") {
        std::string table_name = m_tokens[0];
        m_tokens.erase(m_tokens.begin());
        try {
            m_tools->Update(table_name, m_tokens);
        }
        catch (std::exception& ex) {
            std::cout << "Error: " << ex.what() << std::endl;
        }
    }
    else if (what_to_do == "HELP") {
        if (m_tokens.size() == 0) {
            std::cout << BigHelpMessage << std::endl;
        }
        else {
            if (m_tokens[0] == "MOVIE") std::cout << Help_Movie << std::endl;
            else if (m_tokens[0] == "GENRE") std::cout << Help_Genre << std::endl;
            else if (m_tokens[0] == "MOVIEGENRE") std::cout << Help_MovieGenre << std::endl;
            else if (m_tokens[0] == "PRODUCTION") std::cout << Help_Production << std::endl;
            else if (m_tokens[0] == "COUNTRY") std::cout << Help_Country << std::endl;
            else if (m_tokens[0] == "DIRECTOR") std::cout << Help_Director << std::endl;
            else if (m_tokens[0] == "DIRECTORMOVIE") std::cout << Help_DirectorMovie << std::endl;
            else if (m_tokens[0] == "GET-M") std::cout << Help_Get_m << std::endl;
            else if (m_tokens[0] == "GET-S") std::cout << Help_Get_s << std::endl;
            else if (m_tokens[0] == "INSERT") std::cout << Help_Insert << std::endl;
            else if (m_tokens[0] == "UPDATE") std::cout << Help_Update << std::endl;
            else if (m_tokens[0] == "DELETE") std::cout << Help_Delete << std::endl;
            else if (m_tokens[0] == "Stop") std::cout << Help_Stop << std::endl;
            else std::cout << "Unknown args!\n" << BigHelpMessage << std::endl;
        }
    }
    return true;
}
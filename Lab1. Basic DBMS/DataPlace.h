#ifndef DataPlace_h
#define DataPlace_h

#include <map>
#include <iostream>
#include <memory>
#include <fstream>

template<typename T>
class DataPlace {
public:
    std::map<int, std::shared_ptr<T>> m_data;//id to element
    void Delete(int ID) {
        if (m_data.erase(ID)) {
            std::cout << "Done!\n";
        }
        else {
            std::cout << "Doesn't exist but ok!\n";
        }
    }
    bool Save(std::shared_ptr<T> element) {
        if (!is_exist(element)) {
            try {
                m_data[element->Get_ID()] = element;
                std::cout << "Successfull saving! " << element->Get_table_name() << " ID: " << element->Get_ID() << std::endl;
            }
            catch (...) {
                std::cerr << "Saving Error!" << std::endl;
                return false;
            }
            return true;
        }
        else {
            std::cerr << "Element exists(" << std::endl;
            return false;
        }
    }

    bool is_exist(std::shared_ptr<T> element) {
        if (m_data.find(element->Get_ID()) == m_data.end()) {
            return false;
        }
        return true;
    }
    std::shared_ptr<T> Get(int ID) {
        if (m_data.find(ID) == m_data.end()) {
            throw std::runtime_error("Doesn't exist");
        }
        else {
            return m_data[ID];
        }
    }
};
#endif 

#ifndef DataPlace_h
#define DataPlace_h

#include <map>
#include <iostream>
#include <memory>
#include <fstream>
using namespace std;

template<typename T>
class DataPlace {
public:
    map<int, shared_ptr<T>> m_data;//id to element
    void Delete(int ID) {
        if (m_data.erase(ID)) {
            cout << "Done!\n";
        }
        else {
            cout << "Doesn't exist but ok!\n";
        }
    }
    bool Save(shared_ptr<T> element) {
        if (!is_exist(element)) {
            try {
                m_data[element->Get_ID()] = element;
                cout << "Successfull saving! " << element->Get_table_name() << " ID: " << element->Get_ID() << endl;
            }
            catch (...) {
                cerr << "Saving Error!" << endl;
                return false;
            }
            return true;
        }
        else {
            cerr << "Element exists(" << endl;
            return false;
        }
    }

    bool is_exist(shared_ptr<T> element) {
        if (m_data.find(element->Get_ID()) == m_data.end()) {
            return false;
        }
        return true;
    }
    shared_ptr<T> Get(int ID) {
        if (m_data.find(ID) == m_data.end()) {
            throw runtime_error("Doesn't exist");
        }
        else {
            return m_data[ID];
        }
    }
};
#endif #pragma once

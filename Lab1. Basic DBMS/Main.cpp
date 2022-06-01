#include <iostream>
#include "Tables.h"
#include "DataPlace.h"
#include "Tools.h"
#include "Interface.h"

using namespace std;

int main(int argc, const char* argv[]) {
    bool flag = 1;
    Interface interface;
    while (flag) {
        flag = interface.Command_getter();
    }

    return 0;
}
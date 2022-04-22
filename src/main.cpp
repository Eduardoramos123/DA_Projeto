#include <string.h>

#include "scenarios.h"

using namespace std;

int main(int argc, char* argv[]) {
    /*
    if (argc != 2) {
        cout << "usage: " << argv[0] << " <scenario nr>" << endl;
        return 1;
    }

    if (strcmp(argv[1], "1") && 
            strcmp(argv[1], "2") &&
            strcmp(argv[1], "3")) {
        cout << "enter a scenario nr between 1 and 3." << endl;
        return 1;
    }
    */
    Scenarios scenarios;
    scenarios.scenario2();
    /*
    if (!strcmp(argv[1], "1"))
        scenarios.scenario1();
    else if (!strcmp(argv[1], "2"))
        scenarios.scenario2();
    else if(!strcmp(argv[1], "3"))
        scenarios.scenario3();
    */
    return 0;
}

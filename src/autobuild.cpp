#include "../include/autobuild.hpp"

#include <iostream>

using namespace std;
using namespace Autobuild;

int main(int argc, char** argv)
{
    AutobuildRepo repo;
    int result = repo.readAutobuildFile();
    
    for (int i = 0; i < repo.targets.size(); i++)
    {
        cout << "Type: " << repo.targets[i].type << endl;
        cout << "Platform: " << repo.targets[i].platform << endl;
        cout << "File: " << repo.targets[i].filenameOutput << endl;
        cout << endl;
    }

    return 0;
}
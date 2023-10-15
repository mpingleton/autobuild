#include "../include/autobuild.hpp"

#include <iostream>

using namespace std;
using namespace Autobuild;

int main(int argc, char** argv)
{
    AutobuildRepo repo;
    int result = repo.readAutobuildFile();
    
    cout << "Compiling source groups... ";
    repo.compileSourceGroups();
    cout << "done!" << endl;

    for (int i = 0; i < repo.targets.size(); i++)
    {
        cout << "(Type: " << repo.targets[i].type << ", ";
        cout << "Platform: " << repo.targets[i].platform << ", ";
        cout << "File: " << repo.targets[i].filenameOutput << ")" << endl;

        for (int s = 0; s < repo.targets[i].sourceGroupIds.size(); s++)
        {
            cout << "\tSource group: " << repo.targets[i].sourceGroupIds[s] << endl;
        }

        if (repo.targets[i].platform != "win32")
        {
            cout << "\tSkipping this target because of incompatible platform." << endl;
        }
        else
        {
            cout << "\tBuilding this target... ";
            repo.targets[i].build(repo.sourceGroups);
            cout << "done!" << endl;
        }
    }

    return 0;
}
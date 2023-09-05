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
        cout << "Target #" << i << endl;
        cout << "Type: " << repo.targets[i].type << endl;
        cout << "Platform: " << repo.targets[i].platform << endl;
        cout << "File: " << repo.targets[i].filenameOutput << endl;

        for (int s = 0; s < repo.targets[i].sourceFiles.size(); s++)
        {
            cout << "\tSource file (" << repo.targets[i].sourceFiles[s].type << "): " << repo.targets[i].sourceFiles[s].filename << endl;
        }

        for (int s = 0; s < repo.targets[i].sourceGroupIds.size(); s++)
        {
            cout << "\tSource group: " << repo.targets[i].sourceGroupIds[s] << endl;
        }

        cout << endl;
    }

    for (int i = 0; i < repo.sourceGroups.size(); i++)
    {
        cout << "Source group #" << i << endl;
        cout << "Id: " << repo.sourceGroups[i].id << endl;

        for (int s = 0; s < repo.sourceGroups[i].sourceFiles.size(); s++)
        {
            cout << "\tSource file (" << repo.sourceGroups[i].sourceFiles[s].type << "): " << repo.sourceGroups[i].sourceFiles[s].filename << endl;
        }

        cout << endl;
    }

    return 0;
}
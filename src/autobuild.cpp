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
        repo.targets[i].initObjectFiles();
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
            continue;
        }

        cout << "\tCompiling source files for this target...";
        repo.targets[i].executeCompileJobs();
        cout << "done!" << endl;

        cout << "\tLinking all object files to " << repo.targets[i].filenameOutput << "... ";
        repo.targets[i].linkObjects(repo.sourceGroups);
        cout << "done!" << endl;
    }

    return 0;
}
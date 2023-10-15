#include "../include/autobuild.hpp"

#include <iostream>

using namespace std;
using namespace Autobuild;

int main(int argc, char** argv)
{
    AutobuildRepo repo;
    int result = repo.readAutobuildFile();
    
    for (int i = 0; i < repo.sourceGroups.size(); i++)
    {
        repo.sourceGroups[i].initObjectFiles();
        cout << "Compiling source group " << repo.sourceGroups[i].id << "..." << endl;

        for (int s = 0; s < repo.sourceGroups[i].compileJobs.size(); s++)
        {
            cout << "\tCompiling " << repo.sourceGroups[i].compileJobs[s].source.filename << " -> " << repo.sourceGroups[i].compileJobs[s].object.filename << "... ";
            repo.sourceGroups[i].compileJobs[s].execute();
            cout << "done!" << endl;
        }

        cout << endl;
    }

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

        for (int s = 0; s < repo.targets[i].compileJobs.size(); s++)
        {
            cout << "\tCompiling " << repo.targets[i].compileJobs[s].source.filename << " -> " << repo.targets[i].compileJobs[s].object.filename << "... ";
            repo.targets[i].compileJobs[s].execute();
            cout << "done!" << endl;
        }

        cout << "\tLinking all object files to " << repo.targets[i].filenameOutput << "... ";
        repo.targets[i].linkObjects(repo.sourceGroups);
        cout << "done!" << endl;
    }

    return 0;
}
#include "../../include/autobuild.hpp"

#include <iostream>

using namespace Autobuild;

int Target::linkObjects(std::vector<SourceGroup> sourceGroups)
{
    // Build the command for linking the object files.
    std::string command = "clang++";

    // Executable output.
    command.append(" ");
    command.append("-o");
    command.append(" ");
    command.append(".\\bin\\");
    command.append(filenameOutput);

    // Object file inputs.
    for (int i = 0; i < compileJobs.size(); i++)
    {
        command.append(" ");
        command.append(".\\obj\\");
        command.append(compileJobs[i].object.path);
        command.append(compileJobs[i].object.filename);
    }

    // TODO: Source group object file inputs.
    for (int i = 0; i < sourceGroupIds.size(); i++)
    {
        bool sourceGroupFound = false;
        for (int l = 0; l < sourceGroups.size(); l++)
        {
            if (sourceGroups[l].id == sourceGroupIds[i])
            {
                for (int a = 0; a < sourceGroups[l].compileJobs.size(); a++)
                {
                    command.append(" ");
                    command.append(".\\obj\\");
                    command.append(sourceGroups[l].compileJobs[a].object.path);
                    command.append(sourceGroups[l].compileJobs[a].object.filename);
                }

                sourceGroupFound = true;
                break;
            }
        }

        if (!sourceGroupFound)
        {
            return -1;
        }
    }

    // TODO: A system() call is inefficient.  Find a better alternative.
    system(command.c_str());
    return 0;
}
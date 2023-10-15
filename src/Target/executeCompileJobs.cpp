#include "../../include/autobuild.hpp"

using namespace Autobuild;

int Target::executeCompileJobs()
{
    for (int jobIndex = 0; jobIndex < compileJobs.size(); jobIndex++)
    {
        compileJobs[jobIndex].execute();
    }

    return 0;
}
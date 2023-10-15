#include "../../include/autobuild.hpp"

using namespace Autobuild;

int SourceGroup::executeCompileJobs()
{
    for (int jobIndex = 0; jobIndex < compileJobs.size(); jobIndex++)
    {
        compileJobs[jobIndex].execute();
    }

    return 0;
}
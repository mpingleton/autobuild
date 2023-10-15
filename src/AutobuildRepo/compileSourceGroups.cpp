#include "../../include/autobuild.hpp"

using namespace Autobuild;

int AutobuildRepo::compileSourceGroups()
{
    for (int sourceGroupIndex = 0; sourceGroupIndex < sourceGroups.size(); sourceGroupIndex++)
    {
        sourceGroups[sourceGroupIndex].initObjectFiles();
        sourceGroups[sourceGroupIndex].executeCompileJobs();
    }

    return 0;
}
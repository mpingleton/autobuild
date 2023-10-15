#include "../../include/autobuild.hpp"

using namespace Autobuild;

int Target::build(std::vector<SourceGroup> sourceGroups)
{
    initObjectFiles();
    executeCompileJobs();
    linkObjects(sourceGroups);

    return 0;
}
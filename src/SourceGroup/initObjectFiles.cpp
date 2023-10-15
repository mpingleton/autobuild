#include "../../include/autobuild.hpp"

using namespace Autobuild;

void SourceGroup::initObjectFiles()
{
    for (int i = 0; i < compileJobs.size(); i++)
    {
        compileJobs[i].initObjectFile();
    }
}
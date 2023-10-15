#include "../../include/autobuild.hpp"

using namespace Autobuild;

void CompileJob::initObjectFile()
{
    object.path = source.path;
    object.filename = "";
    
    std::string tmpFilename = source.filename; // Replace the .c or .cpp extension with a .o
    for (int i = tmpFilename.length() - 1; i >= 0; i--)
    {
        if (tmpFilename[i] == '.')
        {
            if (i > 0)
            {
                std::string f = tmpFilename.substr(0, i);
                f.append(".o");
                object.filename = f;
                break;
            }
        }
    }
}
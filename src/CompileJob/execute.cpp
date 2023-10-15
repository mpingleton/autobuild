#include "../../include/autobuild.hpp"

#include <iostream>

using namespace Autobuild;

int CompileJob::execute()
{
    // Build the command for compiling the source file.
    std::string command = "clang++";
    
    // Object file output.
    command.append(" ");
    command.append("-c");
    command.append(" ");
    command.append("-o");
    command.append(" ");
    command.append(".\\obj\\");
    command.append(object.path);
    command.append(object.filename);
    
    // Source file input.
    command.append(" ");
    command.append(".\\src\\");
    command.append(source.path);
    command.append(source.filename);
    
    // TODO: A system() call is inefficient.  Find a better alternative.
    system(command.c_str());
    return 0;
}
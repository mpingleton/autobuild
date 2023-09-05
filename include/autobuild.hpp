#ifndef AUTOBUILD_HPP
#define AUTOBUILD_HPP

#include <iostream>
#include <vector>

namespace Autobuild
{

class SourceFile
{
    std::string type;
    std::string path;
    std::string filename;
};

class SourceGroup
{
    std::string id;
    std::vector<SourceFile> sourceFiles;
};

class Target
{
public:
    std::string filenameOutput;
    std::string platform;
    std::string type;

    std::vector<SourceFile> sourceFiles;
    std::vector<std::string> sourceGroupIds;
};

class AutobuildRepo
{
public:
    std::string path;
    std::vector<Target> targets;
    std::vector<SourceGroup> sourceGroups;

    int readAutobuildFile();
};

}

#endif
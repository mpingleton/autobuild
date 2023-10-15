#ifndef AUTOBUILD_HPP
#define AUTOBUILD_HPP

#include <iostream>
#include <vector>

namespace Autobuild
{

class SourceFile
{
public:
    std::string type;
    std::string path;
    std::string filename;
};

class ObjectFile
{
public:
    std::string path;
    std::string filename;
};

class CompileJob
{
public:
    SourceFile source;
    ObjectFile object;

    int execute();
    void initObjectFile();
};

class SourceGroup
{
public:
    std::string id;
    std::vector<CompileJob> compileJobs;

    void initObjectFiles();
};

class Target
{
public:
    std::string filenameOutput;
    std::string platform;
    std::string type;

    std::vector<CompileJob> compileJobs;
    std::vector<std::string> sourceGroupIds;

    void initObjectFiles();
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
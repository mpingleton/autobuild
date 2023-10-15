@echo on

clang++ -c -o .\obj\AutobuildRepo\readAutobuildFile.o .\src\AutobuildRepo\readAutobuildFile.cpp -I ..\text-parser\include
clang++ -c -o .\obj\AutobuildRepo\compileSourceGroups.o .\src\AutobuildRepo\compileSourceGroups.cpp
clang++ -c -o .\obj\CompileJob\execute.o .\src\CompileJob\execute.cpp
clang++ -c -o .\obj\CompileJob\initObjectFile.o .\src\CompileJob\initObjectFile.cpp
clang++ -c -o .\obj\SourceGroup\initObjectFiles.o .\src\SourceGroup\initObjectFiles.cpp
clang++ -c -o .\obj\SourceGroup\executeCompileJobs.o .\src\SourceGroup\executeCompileJobs.cpp
clang++ -c -o .\obj\Target\executeCompileJobs.o .\src\Target\executeCompileJobs.cpp
clang++ -c -o .\obj\Target\initObjectFiles.o .\src\Target\initObjectFiles.cpp
clang++ -c -o .\obj\Target\linkObjects.o .\src\Target\linkObjects.cpp
clang++ -c -o .\obj\autobuild.o .\src\autobuild.cpp

clang++ -o .\bin\autobuild.exe .\obj\AutobuildRepo\readAutobuildFile.o .\obj\AutobuildRepo\compileSourceGroups.o .\obj\CompileJob\execute.o .\obj\CompileJob\initObjectFile.o .\obj\SourceGroup\initObjectFiles.o .\obj\Target\initObjectFiles.o .\obj\Target\linkObjects.o .\obj\SourceGroup\executeCompileJobs.o .\obj\Target\executeCompileJobs.o .\obj\autobuild.o -I ..\text-parser\include ..\text-parser\bin\text-parser.a
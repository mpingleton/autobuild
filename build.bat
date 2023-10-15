@echo on

clang++ -c -o .\obj\AutobuildRepo\readAutobuildFile.o .\src\AutobuildRepo\readAutobuildFile.cpp -I ..\text-parser\include
clang++ -c -o .\obj\CompileJob\execute.o .\src\CompileJob\execute.cpp
clang++ -c -o .\obj\CompileJob\initObjectFile.o .\src\CompileJob\initObjectFile.cpp
clang++ -c -o .\obj\autobuild.o .\src\autobuild.cpp

clang++ -o .\bin\autobuild.exe .\obj\AutobuildRepo\readAutobuildFile.o .\obj\CompileJob\execute.o .\obj\CompileJob\initObjectFile.o .\obj\autobuild.o -I ..\text-parser\include ..\text-parser\bin\text-parser.a
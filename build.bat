@echo on

clang++ -c -o .\obj\AutobuildRepo\readAutobuildFile.o .\src\AutobuildRepo\readAutobuildFile.cpp -I ..\text-parser\include
clang++ -c -o .\obj\autobuild.o .\src\autobuild.cpp

clang++ -o .\bin\autobuild.exe .\obj\AutobuildRepo\readAutobuildFile.o .\obj\autobuild.o -I ..\text-parser\include ..\text-parser\bin\text-parser.a

# assume you are in as1/code

#g++ -c evalCPP.cpp
g++ -std=c++11 -o fastCPP main.cpp evalCPP.o
./fastCPP
#cp evalCPP.o ../

#----------------------------------------------
#g++ -c evalCPP1.cpp
g++ -o slowCPP evalCPP1.o main.cpp
./slowCPP
#cp evalCPP1.o ../

#----------------------------------------------

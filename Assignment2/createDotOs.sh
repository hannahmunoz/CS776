
# assume you are in as1/code

#g++ -c evalCPP.cpp
g++ -shared -fPIC -o fastCPP main.cpp evalCPP.o
#./fastCPP
#cp evalCPP.o ../

#----------------------------------------------
#g++ -c evalCPP1.cpp
g++ -shared -fPIC -o slowCPP evalCPP1.o main.cpp 
#./slowCPP
#cp evalCPP1.o ../

#----------------------------------------------

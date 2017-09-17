
# assume you are in as1/code
iter=0

g++ -o fastCPP main.cpp evalCPP.o
g++ -o slowCPP evalCPP1.o main.cpp

while [ $iter -le 30 ];
  do
    ./fastCPP fastCPP.txt
    ./slowCPP slowCPP.txt
    let iter=iter+1
  done

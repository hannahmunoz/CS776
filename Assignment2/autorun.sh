
# assume you are in as1/code
iter=0

g++ -std=c++11 -o fastCPP main.cpp evalCPP.o
g++ -std=c++11 -o slowCPP evalCPP1.o main.cpp

#while [ $iter -le 30 ];
  #do
  #  ./fastCPP fastCPP.csv
  #  let iter=iter+1
  #done

iter=0
  while [ $iter -le 30 ];
    do
      ./slowCPP slowCPP5000.csv
      let iter=iter+1
    done

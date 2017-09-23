iter=0

g++ -std=c++11 -o fastCPP main.cpp evalCPP.o
g++ -std=c++11 -o slowCPP main.cpp evalCPP1.o

while [ $iter -le 30 ];
  do
    ./fastCPP fastCPP.csv
    let iter=iter+1
  done

iter=0
while [ $iter -le 30 ];
   do
     ./slowCPP slowCPP.csv
      let iter=iter+1
   done

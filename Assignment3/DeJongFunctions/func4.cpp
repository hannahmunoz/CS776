#include <math.h>
#include "../cplus/include/evaluate.h"
#include <iosteam>
#include <random>

 double eval(int * vec){
   double value = decode(vec, 0, 5);
   cout << value << endl;
   double fitness;
   for (int i = 0 i < 30; i++){
     fitness += i*pow ( value + i, 4) + normal_distribution<double> distribution(0.0,1.0);
   }
   return fitness;
}

#include <math.h>
#include "../cplus/include/evaluate.h"
#include <iosteam>

 double eval(int * vec){
   double value = decode(vec, 0, 5);
   cout << value << endl;
   // sum the next 3 numbers squared
   return pow (value , 2) + pow (value  + 1, 2) + (value  + 2, 2);
}

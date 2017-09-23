#include <math.h>
#include "../cplus/include/evaluate.h"
#include <iosteam>

 double eval(int * vec){
   double value = decode(vec, 0, 5);
   cout << value << endl;
   return ceil(value) + ceil(value  + 1) + ceil(value + 2)+ ceil(value + 3)+ ceil(value + 4);
}

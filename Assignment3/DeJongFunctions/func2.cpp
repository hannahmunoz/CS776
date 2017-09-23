#include <math.h>
#include "../cplus/include/evaluate.h"
#include <iosteam>

 double eval(int * vec){
   double value = decode(vec, 0, 5);
   cout << value << endl;
   return 100 * pow (pow (value , 2) + pow (value + 1, 2), 2) + pow((1-value), 2);
}

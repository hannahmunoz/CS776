#include <iostream>

using namespace std;

double eval(int *vec);

int main()
{
  int vec[150];

  int i;

  for(i = 0; i < 150; i++){
    vec[i] = 1;
  }
  cout << eval(vec) << endl;
  //printf("Fitness = %lf\n", eval(vec));
}

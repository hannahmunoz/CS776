#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

using namespace std;

double eval(int *pj);
double checkNeighbors(int (&vec)[100]);

int main()
{
  int vec[100];
  int vecMax[100];
  double fitness = 0;
  int i;

  // max number of loops to look for the peak point
  int maxTries = 200;
  // initalize srand
  srand (time (NULL));

  //randomize start vector
  for(i = 0; i < 100; i++){
    vec[i] = rand()%2;
  }

// cycle through number of times
for (int j = 0; j < maxTries; j++){

  // check vector's neightbors fitness
  double newfitness = checkNeighbors (vec);

  // if the new fitness is greater than the old one
  if (newfitness > fitness){
    // reset number of times to look for a new hill
    j = 0;
    // and set it as the new fitness
    fitness = newfitness;
    memcpy(vecMax, vec, sizeof(vecMax));
  }
}
  cout << "fitness = " << fitness << endl;
  for(int j = 0; j < 100; j++){
    cout << vecMax[j];
  }
  cout  << endl;

}

double checkNeighbors(int (&vec)[100]){
  double maxFitness = 0;
  int maxVec[100];
  double fitness;

  // cycle through each digit in the vector
  for (int i = 0; i < 100; i++){
    // flip it
    vec[i] = 1 - vec[i];

    //check its fitness
    fitness = eval(vec);

    // if the fitness is more than the current max
    if (fitness >= maxFitness){
      // set it as the new max
      maxFitness = fitness;

      // copy into the max vector
      memcpy(maxVec, vec, sizeof(maxVec));

    }

    //flip the bit back
    vec[i] = 1 - vec[i];
  }

  // once all bits are done

  // copy into vector
  memcpy(vec, maxVec, sizeof(vec));

  // return the max fitness
  return maxFitness;
}

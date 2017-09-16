#include <iostream>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

using namespace std;

int POOL_SIZE = 100;

double eval(int *vec);
void fillPool (int p[100][150]);
void fillVector(int (&vec)[150]);
void checkFitness (double &b, int (&bv)[150],  int (&cv)[150]);
void merge (int (&v1)[150],  int (&v2)[150]);
bool mutate ();
void print (int (&bvec)[150]);

int main()
{
  srand (time (NULL));
  double bestFitness = 0;
  int bvec[150];
  int pool [100][150];
  fillPool (pool);

  /*for (int iter = 0; iter < 10; iter++){
    checkFitness (bestFitness, bvec, vec1);
    checkFitness (bestFitness, bvec, vec2);
    merge (vec1, vec2);
  }*/

  cout << bestFitness << endl;
  print (pool[0]);
}

void fillPool (int p[100][150]){
  for (int i = 0; i < 100; i++){
    int vec[150];
    fillVector (vec);
    memcpy(p[i], vec, sizeof(p[i]));
  }
}

void fillVector(int (&vec)[150]){
  for(int i = 0; i < 150; i++){
    vec[i] = rand()%2;
  }
}

void checkFitness (double &b, int (&bv)[150], int (&cv)[150]){
  double currentFitness = eval (cv);
  //cout << "fitness " << currentFitness <<endl;
  if (currentFitness > b){
    b = currentFitness;
    memcpy(bv, cv, sizeof(bv));
  }
}

void merge (int (&v1)[150],  int (&v2)[150]){
  int splitPoint = rand()%150;
  int temp [150];
  for (int i = 0; i < splitPoint; i++){
    if (mutate){
      temp[i] = 1 - v1[i];
    }
    else{
      temp[i] = v1[i];
    }
    v1[i] = v2[i];
    v2[i] = temp[i];
  }
}

void print (int (&bvec)[150]){
  for (int i = 0; i < 150; i+=50){
    for (int j = 0; j < 50; j++){
      cout << bvec[i+j];
    }
    cout << endl;
  }
}

bool mutate (){
  int test = rand()%1000;
  if (test == 1){
    return true;
  }
  return false;
}

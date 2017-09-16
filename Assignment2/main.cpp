#include <iostream>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

using namespace std;

static const int POOL_SIZE = 1000;
static const int LENGTH = 150;

double eval(int *vec);
void fillPool (int p[POOL_SIZE][LENGTH ]);
double populationFitness (int p[POOL_SIZE ][LENGTH]);
void fillVector(int (&vec)[LENGTH ]);
void roulette(int p[POOL_SIZE][LENGTH], int (&vec)[LENGTH], int &location);
double checkFitness (double &b, int (&bv)[LENGTH],  int (&cv)[LENGTH]);
void merge (int (&v1)[LENGTH],  int (&v2)[LENGTH] );
bool mutate ();
void print (int (&bvec)[LENGTH]);

int main()
{
  srand (time (NULL));
  double bestFitness = 0;
  int bvec[LENGTH];
  int pool [POOL_SIZE ][LENGTH];


  int vec1[LENGTH];
  int vec2[LENGTH];
  int loc1;
  int loc2;

    fillPool (pool);
    cout << populationFitness (pool)/POOL_SIZE << endl;
    for (int iter = 0; iter < 100000; iter++){
      roulette (pool, vec1, loc1);
      roulette (pool, vec2, loc2);
      int t1 = checkFitness (bestFitness, bvec, vec1);
      int t2 = checkFitness (bestFitness, bvec, vec2);
      merge (vec1, vec2);
      if (checkFitness (bestFitness, bvec, vec1) > t1){
        memcpy(pool [loc1], vec1, sizeof(pool [loc1]));
      }
      if (checkFitness (bestFitness, bvec, vec2) > t2){
        memcpy(pool [loc2], vec2, sizeof(pool [loc2]));
      }
    }
      cout << populationFitness (pool)/POOL_SIZE << endl << endl;

  cout << bestFitness << endl;
  print (bvec);
}

void fillPool (int p[POOL_SIZE ][LENGTH]){
  for (int i = 0; i < POOL_SIZE ; i++){
    int vec[LENGTH];
    fillVector (vec);
    memcpy(p[i], vec, sizeof(p[i]));
  }
}

double populationFitness (int p[POOL_SIZE][LENGTH]){
  double sum = 0;
  for (int i = 0; i < POOL_SIZE ; i++){
    sum +=  eval (p[i]);
  }
  return sum;
}

void fillVector(int (&vec)[LENGTH]){
  for(int i = 0; i < LENGTH; i++){
    vec[i] = rand()%2;
  }
}

void roulette(int p[POOL_SIZE ][LENGTH], int (&vec)[LENGTH], int &location){
  location = rand()%POOL_SIZE;
  memcpy(vec, p[location], sizeof(vec));
}

double checkFitness (double &b, int (&bv)[LENGTH], int (&cv)[LENGTH]){
  double currentFitness = eval (cv);
//  cout << "fitness " << currentFitness <<endl;
  if (currentFitness > b){
    b = currentFitness;
    memcpy(bv, cv, sizeof(bv));
  }
  return currentFitness;
}

void merge (int (&v1)[LENGTH],  int (&v2)[LENGTH]){
  int splitPoint = rand()%LENGTH;
  int temp [LENGTH];
  for (int i = 0; i < splitPoint; i++){
    if (mutate){
      temp[i] = 1 - v1[i];
    }
    else{
      temp[i] = v1[i];
    }
    if (mutate){
      v1[i] = 1 - v2[i];
    }
    else{
      v1[i] = v2[i];
    }
    if (mutate){
      v2[i] = 1 - temp[i];
    }
    else{
      v2[i] = temp[i];
    }
  }
}

void print (int (&bvec)[LENGTH]){
  for (int i = 0; i < LENGTH; i+=50){
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

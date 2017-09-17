#include <iostream>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <fstream>

using namespace std;

static const int POOL_SIZE = 500;
static const int LENGTH = 100;
static const int ITER_SIZE = 10;

double eval(int *vec);
void fillPool (int p[POOL_SIZE][LENGTH ]);
double populationFitness (int p[POOL_SIZE ][LENGTH]);
void fillVector(int (&vec)[LENGTH ]);
void roulette(int p[POOL_SIZE][LENGTH], int (&vec)[LENGTH], int &location);
double checkFitness (double &b, int (&bv)[LENGTH],  int cv[LENGTH], int &maxIter, int iter);
void merge (int (&v1)[LENGTH],  int (&v2)[LENGTH] );
bool mutate (int v);
void print (int (&bvec)[LENGTH], int bf, string filename, int maxIter);

int main(int argc, char const *argv[]) {
  if (argc > 1){
    srand (time (NULL));
    double bestFitness = 0;
    int bvec[LENGTH];
    int maxIter;
    int pool [POOL_SIZE][LENGTH];

    int vec1[LENGTH];
    int vec2[LENGTH];
    int loc1;
    int loc2;

    fillPool (pool);
    populationFitness (pool);
    float t = populationFitness (pool)/POOL_SIZE;
    //cout << populationFitness (pool)/POOL_SIZE << endl;
    //memcpy( vec1, pool [0], sizeof(vec1));
    //memcpy( vec2, pool [POOL_SIZE-1], sizeof(vec2));

    for (int iter = 0; iter < ITER_SIZE; iter++){
      roulette (pool, vec1, loc1);
      roulette (pool, vec2, loc2);
      int t1 = checkFitness (bestFitness, bvec, vec1, maxIter, iter);
      int t2 = checkFitness (bestFitness, bvec, vec2, maxIter, iter);
      merge (vec1, vec2);
      if (checkFitness (bestFitness, bvec, vec1, maxIter, iter) > t1){
        memcpy(pool [loc1], vec1, sizeof(pool [loc1]));
      }
      if (checkFitness (bestFitness, bvec, vec2, maxIter, iter) > t2){
        memcpy(pool [loc2], vec2, sizeof(pool [loc2]));
      }

      /*if (float (populationFitness (pool)/POOL_SIZE) > t){
        cout << iter << ": "<< populationFitness (pool)/POOL_SIZE << endl << endl;
        t = populationFitness (pool)/POOL_SIZE;
      }*/
    }
    // cout << populationFitness (pool)/POOL_SIZE << endl << endl;

  //  cout << bestFitness << endl;
    print (bvec, bestFitness, argv[1], maxIter);
  }else{
    cout << "Please run with a output filename." << endl;
  }
}

void fillPool (int p[POOL_SIZE ][LENGTH]){
  int t [LENGTH] = { 1 };
  memcpy(p[POOL_SIZE-1], t, sizeof(p[POOL_SIZE-1]));

  for (int i = 1; i < POOL_SIZE-1; i++){
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

double checkFitness (double &b, int (&bv)[LENGTH], int cv[LENGTH], int &maxIter, int iter){
  double currentFitness = eval (cv);
//  cout << "fitness " << currentFitness <<endl;
  if (currentFitness > b){
    b = currentFitness;
    memcpy(bv, cv, sizeof(bv));
    maxIter = iter;
  }
  return currentFitness;
}

void merge (int (&v1)[LENGTH],  int (&v2)[LENGTH]){
  int splitPoint = rand()%LENGTH;
  int temp [LENGTH];
  for (int i = 0; i < splitPoint; i++){
    temp[i] = mutate (v1[i]);
    v1[i] = mutate (v2[i]);
    v2[i] = mutate (temp[i]);
  }
}

void print (int (&bvec)[LENGTH], int bf, string filename, int maxIter){
  ofstream fout;
  fout.open (filename.c_str(), fstream::app);
  fout << maxIter << ", " << bf << endl;

  cout << "Generations to hit max fitness:" << maxIter << endl
       << "Max fitness: " << bf << endl;
  for (int i = 0; i < LENGTH; i+=50){
    for (int j = 0; j < 50; j++){
      cout << bvec[i+j];
    }
    cout << endl;
  }
}

bool mutate (int v){
  return (rand()%1000 ? (1-v) : v);
}

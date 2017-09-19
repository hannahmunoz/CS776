#include <iostream>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <fstream>

using namespace std;

static const int POOL_SIZE = 450;
static const int LENGTH = 150;
static const int ITER_SIZE = 5000;


struct chrom{
      int vec[LENGTH];
      int location;
      double fitness = 0;
};

double eval(int *vec);
void fillPool (chrom p[POOL_SIZE]);
double populationFitness (chrom p[POOL_SIZE]);
void fillVector(int (&vec)[LENGTH]);
void roulette(chrom p[POOL_SIZE], chrom &parent);
void checkFitness (chrom &b, chrom &p, int iter);
void merge (chrom &p1, chrom &p2);
bool mutate (int v);
void print (chrom b, string filename);

int main(int argc, char const *argv[]) {
  if (argc > 1){
    srand (time (NULL));
    chrom best;
    chrom pool [POOL_SIZE];
    fillPool (pool);

    //cout << populationFitness (pool)/POOL_SIZE << endl;

    for (int iter = 0; iter < ITER_SIZE; iter++){
      chrom parent1;
      chrom parent2;
      roulette (pool, parent1);
      roulette (pool, parent2);
      if (pool[parent1.location].fitness == 0){
        checkFitness (best, pool[parent1.location], iter);
      }
      if (pool[parent2.location].fitness == 0){
        checkFitness (best, pool[parent2.location], iter);
      }
      merge (parent1, parent2);
      checkFitness (best, parent1, iter);
      checkFitness (best, parent2, iter);
      if (parent1.fitness > pool[parent1.location].fitness){
        pool [parent1.location] = parent1;
      }
      if (parent2.fitness > pool[parent1.location].fitness){
        pool[parent1.location] = parent1;
      }
    }

    //cout << populationFitness (pool)/POOL_SIZE << endl << endl;
    print (best, argv[1]);
  }else{
    cout << "Please run with a output filename." << endl;
  }
}

void fillPool (chrom p[POOL_SIZE ]){

  for (int i = 1; i < POOL_SIZE-1; i++){
    chrom vec;
    vec.location = i;
    fillVector (vec.vec);
    p[i] = vec;
  }
  chrom t;
  for (int i = 1; i < LENGTH; i++){
    t.vec[i] =  1;
    t.location = POOL_SIZE-1;
    p[POOL_SIZE-1] = t;
  }
}

double populationFitness (chrom p[POOL_SIZE]){
  double sum = 0;
  for (int i = 0; i < POOL_SIZE ; i++){
    sum +=  eval (p[i].vec);
  }
  return sum;
}

void fillVector(int (&vec)[LENGTH]){
  for(int i = 0; i < LENGTH; i++){
    vec[i] = rand()%2;
  }
}

void roulette(chrom p[POOL_SIZE], chrom &parent){
  parent = p[rand()%POOL_SIZE];
}

void checkFitness (chrom &b, chrom &p, int iter){
  p.fitness = eval (p.vec);

  if (p.fitness > b.fitness){
    b = p;
    b.location = iter;
  }
}

void merge (chrom &p1, chrom &p2){
  int splitPoint = rand()%LENGTH;
  int temp [LENGTH];
  for (int i = 0; i < splitPoint; i++){
    temp[i] = mutate (p1.vec[i]);
    p1.vec[i] = mutate (p2.vec[i]);
    p2.vec[i] = mutate (temp[i]);
  }
}

void print (chrom b, string filename){
  ofstream fout;
  fout.open (filename.c_str(), fstream::app);
  fout << b.location << ", " << b.fitness << endl;

  cout << "Generations to hit max fitness:" << b.location << endl
       << "Max fitness: " << b.fitness << endl;
  for (int i = 0; i < LENGTH; i+=50){
    for (int j = 0; j < 50; j++){
      cout << b.vec[i+j];
    }
    cout << endl;
  }
}

bool mutate (int v){
  return (rand()%1000 ? (1-v) : v);
}

/*
 * evaluate.cpp
 *
 *  Created on: Feb 3, 2016
 *      Author: sushil
 */

#include <evaluate.h>
#include <utils.h>
#include <const.h>

#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <math.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <assert.h>

using namespace std;

void evaluate(ga::Individual *ent){
	//cout << *ent << endl;
	double sum = 0;
	for(int i = 0; i < ent->length; i++){
		sum += ent->chrom[i];
	}
	ent->fit = sum;
	for(int i = 0; i < ga::MAX_CRITERIA; i++){
		ent->fitness[i] = sum;
	}

//	cout << "----------------------------------------" << endl;

}

double decode(int * chrom, int start, int end){
  double prod = 0;
  for (int i = start; i < end; i++){
    prod += (chrom[i] == 0 ? 0 : pow(2.0, (double) i));
  }
	cout << prod << endl;
  return prod;
}

void xSquared(ga::Individual *ent) {
  int value = decode(ent->chrom, 0, ent->length);
  ent->fit = value * value;
  return;
}

void firstDejong(ga::Individual *ent, ga::Individual *ent1, ga::Individual *ent2){
	float value1 = decode (ent->chrom ,0, ent->length, float(-5.12),float (5.12));
	float value2 =	decode (ent1->chrom ,0, ent->length, float(-5.12),float (5.12));
	float value3 =	decode (ent2->chrom ,0, ent->length, float(-5.12),float (5.12));

	ent->fit = (pow (value1, 2) + pow (value2, 2) + pow (value3, 2));
	return;
}

void secondDejong(ga::Individual *ent, ga::Individual *ent1){
	double value = decode (ent->chrom ,0, ent->length, float(-2.048),float (2.048));
	double value1 = decode (ent1->chrom ,0, ent->length, float(-2.048),float (2.048));
	ent->fit = 100 * pow ((pow (value , 2) - value1), 2) + pow(1-value, 2);
	return;
}

void thirdDejong(ga::Individual *ent){
	/*double value = decode(vec, 0, 5);
	cout << value << endl;
	return ceil(value) + ceil(value  + 1) + ceil(value + 2)+ ceil(value + 3)+ ceil(value + 4);*/
}

void fourthDejong(ga::Individual *ent){
	/*double value = decode(vec, 0, 5);
	cout << value << endl;
	double fitness;
	for (int i = 0 i < 30; i++){
		fitness += i*pow ( value + i, 4) + normal_distribution<double> distribution(0.0,1.0);
	}
	return fitness;*/
}

void fithDejong(ga::Individual *ent){

}

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

#include <random>

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

void firstDejong(ga::Individual *ent){
	for (int i = 0; i < 3; i++){
		ent->fit += pow (decode (ent->chrom, ent->length/3*i, (ent->length/3)*(i+1), -5.12, 5.12),2);
	}
	ent->fit = 1/ent->fit;
}

void secondDejong(ga::Individual *ent){
	float value = decode (ent->chrom ,0, ent->length/2, -2.048, 2.048);
	float value1 = decode (ent->chrom , ent->length/2, ent->length, -2.048, 2.048);

	ent->fit = 1/log ((100 * pow ((pow (value , 2) - value1), 2) + pow(1-value, 2)));
}

void thirdDejong(ga::Individual *ent){
	double value;
	for (int i = 0; i < 5; i++){
		value += (int) decode (ent->chrom ,ent->length/5*i, ent->length/5*(i+1), -5.12, 5.12);
	}
	ent->fit = 1/value;

}

void fourthDejong(ga::Individual *ent){
	float value;
	default_random_engine generator;
	normal_distribution<double> distribution(0.0,1.0);
	for (int i = 0; i < 30; i++){
		value = decode (ent->chrom ,ent->length/30*i, ent->length/30*(i+1), -1.28, 1.28);
		ent->fit += i*pow ( value, 4) + distribution(generator);
	}
	ent->fit = 1/ent->fit;
}

void fithDejong(ga::Individual *ent){

}

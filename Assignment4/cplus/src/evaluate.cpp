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
//	cout << *ent << endl;
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

void euclideanDistance(ga::Individual *ent, std::vector <float> latitude, std::vector <float> longitude){
	double sum = 0;
	double x, y;
		for (int i = 0; i < ent->length-1; i++){
			 x = abs ((int)latitude [ent->chrom [i]] - (int)latitude [ent->chrom [i+1]]);
			 y = abs ((int)longitude [ent->chrom [i]] - (int)longitude [ent->chrom [i+1]]);
			 sum += sqrt (x*x+y*y);
		}
	  x = abs ((int)latitude [ent->chrom [ent->length-1]] - (int)latitude [ent->chrom [0]]);
	  y = abs ((int)longitude [ent->chrom [ent->length-1]] - (int)longitude [ent->chrom [0]]);
	  sum += sqrt (x*x+y*y);
	 //
	 	ent->fit = (int) 1/sum;
		//std::cout << 1/sum << std::endl;
}

void euclideanDistanceGeo(ga::Individual *ent, std::vector <float> latitude, std::vector <float> longitude){
	float sum = 0;
	float q1, q2, q3;
		for (int i = 0; i < ent->length-1; i++){
			q1 = cos (longitude [ent->chrom [i]] - longitude [ent->chrom [i+1]]);
			q2 = cos(latitude [ent->chrom [i]] - latitude [ent->chrom [i+1]]);
			q3 = cos(latitude [ent->chrom [i]] + latitude [ent->chrom [i+1]]);
			sum += (6378.388 * acos(0.5 * ((1+q1)*q2- (1-q1)*q3))+1);
		}
		q1 = cos (longitude [ent->chrom [ent->length-1]] - longitude [ent->chrom [0]]);
		q2 = cos(latitude [ent->chrom [ent->length-1]] - latitude [ent->chrom [0]]);
		q3 = cos(latitude [ent->chrom [ent->length-1]] + latitude [ent->chrom [0]]);
		sum += (6378.388 * acos(0.5 * ((1+q1)*q2- (1-q1)*q3))+1);

		ent->fit = (int)1/sum;
		//std::cout << 1/sum << std::endl;
}

double decode(int * chrom, int start, int end){
  double prod = 0;
  for (int i = start; i < end; i++){
    prod += (chrom[i] == 0 ? 0 : pow(2.0, (double) i));
  }
  return prod;
}

void xSquared(ga::Individual *ent) {
  int value = decode(ent->chrom, 0, ent->length);
  ent->fit = value * value;
  return;

}

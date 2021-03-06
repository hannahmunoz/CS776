/*
 * individual.cpp
 *
 *  Created on: Feb 3, 2016
 *      Author: sushil
 */

#include <individual.h>
#include <stdlib.h>
#include <random.h>
#include <assert.h>

using namespace std;
using namespace ga;

Individual::Individual(){
	length = 0;
	setup();
}

Individual::Individual(int len){
	length = len;
	setup();
}

void Individual::setup(){
	for(int i = 0; i < length; i++){
		this->chrom[i] = -1;
	}
}


void Individual::init(int len, vector <int> &dataset, vector <float> &latitude, vector <float> &longitude){
	assert(len <= MAX_CHROM_LENGTH);
	length = len;
	std::vector<int> marker;
	marker.resize (dataset.size()+1);
	fill(marker.begin(), marker.end(), 0);

	for(int i = 0; i < length; i++){
		int temp = intInRange(0, dataset.size()+1);
		while (marker[temp] != 0){
			temp = intInRange(0, dataset.size()+1);
		}
		this->chrom[i] = temp;
		marker [temp] = 1;
	//	cout << this->chrom[i] << " ";
	}
//	cout << endl;
}



void Individual::mutate(float prob, int length){
	for(int i = 0; i < length; i++){
		if(flip(prob) == 1){
			int x = intInRange(0, length);
			int temp = chrom[i];
			chrom[i] = chrom[x];
			chrom[x] = temp;
		}
	}
}

void Individual::copy(Individual *ip){
	assert(ip->length <= MAX_CHROM_LENGTH);
	this->length = ip->length;
	for(int i = 0; i < length; i++){
		this->chrom[i] = ip->chrom[i];
	}
	for(int i = 0; i < MAX_CRITERIA; i++){
		this->fitness[i] = ip->fitness[i];
		this->objectives[i] = ip->objectives[i];
	}
	this->fit = ip->fit;
	this->scaledFit = ip->scaledFit;
}

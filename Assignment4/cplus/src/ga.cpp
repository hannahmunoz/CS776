//============================================================================
// Name        : ga.cpp
// Author      : Sushil J Louis
// Version     :
// Copyright   : Copyright University of Nevada, Reno
// Description : GA in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <utils.h>
#include <population.h>
#include <ga.h>
#include <random.h>


using namespace std;
using namespace ga;



int main(int argc, char *argv[]) {
	GA ga = GA(argc, argv);

	 ga.init();
	 //ga.run();
	 //ga.report();

	return 0;
}

GA::GA(int argc, char *argv[]){

	setupOptions(argc, argv);
	srandom(options.randomSeed);
	ofstream ofs(options.outfile, std::ofstream::out | std::ofstream::trunc);
	ofs.close();
	ofstream pofs(options.phenotypeFile, std::ofstream::out | std::ofstream::trunc);
	pofs.close();
	maxFitGen = 0;
	this->bestIndividualSoFar = new Individual(options.chromLength);
	bestFitnessSoFar = -1;
}


void GA::init(){
	parent = new Population(options);
	child  = new Population(options);
	parent->initialize(); // evaluates, stats, and reports on initial population
	updateProgress(0, parent);
//	cout << "initialized" << endl;
}



//
//void GA::CHC(Population *p, Population *c){
//}

void GA::run(){//chc

	Population *tmp;
	for (unsigned int i = 1; i < options.maxgens; i++){
	  //		parent->chc(child);
	        parent->generation(child);
		child->statistics();
		child->report(i);

		updateProgress(i, child);

		tmp = parent;
		parent = child;
		child = tmp;
		//cout << "Generation: " << i << endl;
	}

}

/**
 * Update and save the best ever individual
 */
void GA::updateProgress(unsigned int gen, Population *p){

  if (p->max > bestFitnessSoFar){
    bestFitnessSoFar = p->max;
    maxFitGen = gen;
    bestIndividualSoFar->copy(p->pop[p->maxi]);

    char printbuf[1024];
    char chromString[MAX_CHROM_LENGTH+1];
    chromToString(bestIndividualSoFar->chrom, bestIndividualSoFar->length, chromString);
    sprintf(printbuf, "%4i \t %f \t %s\n", maxFitGen, bestFitnessSoFar, chromString);
    writeBufToFile(printbuf, options.phenotypeFile);
  }

}


void GA::report(){
  //parent->report(options.maxgens);
  cout << *(parent->pop[parent->maxi]) << endl;
}

void GA::configure(vector <int> &dataset, vector <float> &latitude, vector <float> &longitude, int &length){
	ifstream ifs(options.infile);
	string temp;
	if(ifs.good()){
		while (temp.compare ("DIMENSION:") != 0){
			ifs >> temp;
		}
		ifs >> length; //dimension
		while (temp.compare ("NODE_COORD_SECTION") != 0){
			ifs >> temp;
		}
		for (int i = 0; i < length; i++){
			int t;
			float j;
			ifs >> t;
			options.dataset.push_back (t);
			ifs >> j;
			options.latitude.push_back (j);
			ifs >> j;
			options.longitude.push_back (j);
		}
 options.chromLength++;
	}
	ifs.close();
}

void GA::setupOptions(int argc, char *argv[]){

	options.randomSeed = 189;
	options.infile = string("infile");
	options.outfile = string("outfile");// append randomseed to output file names

	options.popSize = 10;
	options.chromLength = 10;
	options.maxgens = 10;
	options.px = 0.7f;
	options.pm = 0.001f;
	options.scaler = 1.05;
	options.lambda = 2;
	options.nCriteria   = 1;

	options.mutator = Mutator::Flip;
	options.xover = Xover::UX;
	options.selector = Selector::Proportionate;

	if(argc == 4){
		options.infile = string(argv[1]);
		options.outfile = string(argv[2]);
		options.randomSeed = atoi(argv[3]);
		configure(options.dataset, options.latitude, options.longitude, options.chromLength);
	}

	//derived values go after configure() above
	options.phenotypeFile   = string(options.outfile + ".pheno"); //derived from options.outfile
	//options.maxgens = options.popSize * 1.5;


}

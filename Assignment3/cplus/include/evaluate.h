/*
 * evaluate.h
 *
 *  Created on: Mar 15, 2016
 *      Author: sushil
 */

#ifndef EVALUATE_H_
#define EVALUATE_H_

#include <individual.h>
#include <cstring>

void evaluate(ga::Individual *ent);
void xSquared(ga::Individual *ent);
void convertToString(int *vec, int size, char *chrom);

void firstDejong(ga::Individual *ent);
void secondDejong(ga::Individual *ent);
void thirdDejong(ga::Individual *ent);
void fourthDejong(ga::Individual *ent);
void fithDejong(ga::Individual *ent);

#endif /* EVALUATE_H_ */

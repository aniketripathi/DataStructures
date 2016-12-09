/*
 * hashTable.h
 *
 *  Created on: 09-Dec-2016
 *      Author: Aniket
 */

#ifndef HASHTABLE_H_
#define HASHTABLE_H_

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

#define 	A		1.61803398875
#define		B		3.14159265359
#define		C		2.71828182846

#define INF			LONG_MAX

typedef struct {
	long int *arr;
	long int maxSize;
	long int collisions;
}HashTable;

HashTable *createHashTable(long int maxSize);

void destoryHashTable(HashTable *hashTable);

long int hashFunction1(long int key, long int hashSize, long int probValue);

long int hashFunction2(long int key, long int hashSize, long int probValue);

long int hashFunction3(long int key, long int hashSize, long int probValue);

long int hashFunction(long int key, long int hashSize, long int probValue);

long int getHashCollisions(HashTable *hashTable);

void hashDelete(HashTable *hashTable, long int key);

long int hashSearch(HashTable *hashTable, long int key);

void hashInsert(HashTable *hashTable, long int key);

#endif /* HASHTABLE_H_ */

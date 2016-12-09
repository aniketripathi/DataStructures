/*
 * hashTable.c
 *
 *  Created on: 09-Dec-2016
 *      Author: Aniket
 */
#include "../inc/hashTable.h"

HashTable *createHashTable(long int maxSize){

	/** allocate memory **/
	HashTable *hashTable = malloc(sizeof(HashTable));
	if(hashTable != NULL){
		hashTable->arr = malloc(sizeof(long int) * maxSize);

/** set initial value to the hashTable, it will help to identify whether hash table is empty or not **/
		long int i;
		for(i = 0; i < maxSize; i++)		hashTable->arr[i] = INF;

		hashTable->maxSize = maxSize;
	}
	return hashTable;
}


void destroyHashTable(HashTable **hashTable){
		free((*hashTable)->arr);
		free(*hashTable);
		*hashTable = NULL;
}


/**
 * Multiplication method for hash function using quadratic probing
 */
long int hashFunction1(long int key, long int m, long int i){
	long int hashValue;

	hashValue = (long int) (m * fmod( key * A, 1) );
/** quadratic probing **/
	hashValue +=  (i*i);
	return hashValue;
}

/**
 * division method
 */
long int hashFunction2(long int key, long int m, long int i){
	long int hashValue;

		hashValue = key % m;
	/** quadratic probing **/
		hashValue +=  (i*i);
	return hashValue;
}


long int hashFunction3(long int key, long int m, long int i){
		return (hashFunction1(key, m, i) + hashFunction2(key, m , i))/2 ;
}


/** hash function currently in use **/
long int hashFunction(long int key, long int m, long int i){
	return (hashFunction1(key, m, i));
}


void hashInsert(HashTable *hashTable, long int key){
	char isInserted = 0;

	long int i = 0;
	while((i*i) < hashTable->maxSize){
		long int slot = hashFunction(key, hashTable->maxSize, i);
		printf("%ld,", slot);
		if(slot >= hashTable->maxSize)		break;

		else if(hashTable->arr[slot] == INF){
			hashTable->arr[slot] = key;
			isInserted = 1;
			break;
		}
		else
		 ++(hashTable->collisions);
		++i;
	}

	if(!isInserted)			fputs("Hash Table overflow.\n", stderr);
}




long int hashSearch(HashTable *hashTable, long int key){
	long int i = 0;

	while((i*i) < hashTable->maxSize){
			long int slot = hashFunction(key, hashTable->maxSize, i);

			 if(slot >= hashTable->maxSize || hashTable->arr[slot] == INF)			break;

			 else if(hashTable->arr[slot] == key)			return slot;

			 	 ++i;
		}

	return -1;
}



void hashDelete(HashTable *hashTable, long int key){

	long int slot = hashSearch(hashTable, key);
		if(slot == -1)		fputs("Element not present in hash table.\n", stderr);
		else				hashTable->arr[slot] = INF;
	}



long int getHashCollisions(HashTable *hashTable){
		return (hashTable->collisions);
}

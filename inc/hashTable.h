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

/**
 * @brief constant A with value golden ratio
 */
#define 	A		1.61803398875

/**
 * @brief constant B with value PI
 */
#define		B		3.14159265359

/**
 * @brief constant C with value e
 */
#define		C		2.71828182846

/**
 * @brief Sentinel defined to check whether the hash table is empty or not. The hash table created
 * will be initialized with INF by default.
 */
#define INF			LONG_MAX

/**
 * @brief Structure defining Hash Table. It consists of array, maxSize to store the maximum size of the
 *  hash table, and collisions to store the number of collisions occurred while insertion.
 */
typedef struct {

	/**
	 * @brief Array where keys will be stored.
	 */
	long int *arr;

	/**
	 * @brief Stores the maximum size of the hash table.
	 */
	long int maxSize;

	/**
	 * @brief Number of collisions occurred while insertion.
	 */
	long int collisions;
}HashTable_t;


/**
 * @brief Creates a hash table.
 *
 * Creates a hash table dynamically. It also allocates memory dynamically to the array of hash table.
 * It clears out the hash table with default value INF. Once you are done with hash table, destroy the table
 * using destroyHashTable function.
 *
 * @param maxSize Size of hash table to be created.
 * @return Address of the hash table created.
 */
HashTable_t *createHashTable(long int maxSize);



/**
 * @brief Destroys a hash table.
 *
 * It deallocates all the memory given to array of hash table and to the hash table dynamically.
 * It also sets the hash table pointer to NULL for safe use.
 *
 * @param hashTable Hash Table to be destroyed. Address of the pointer to hashTable.
 * @return void. Returns nothing.
 */
void destoryHashTable(HashTable_t **hashTable);


/**
 * @brief Hash Function returning the slot value.
 *
 * Hash Function 1 calculates the slot of the key using multiplication method. By default the constant
 * used is A which is defined previously. Quadratic probing is used.
 *
 * @param key Key to be stored.
 * @param hashSize hashSize is the size of the hashTable. It is the mod factor.
 * @param probValue Probing value used to determine hash value in quadratic probing.
 * @return Value of the slot calculated.
 */
long int hashFunction1(long int key, long int hashSize, long int probValue);


/**
 * @brief Hash Function returning the slot value.
 *
 * Hash Function 2 calculates the slot of the key using division method. By default the constant
 * used is A which is defined previously. Quadratic probing is used.
 *
 * @param key Key to be stored.
 * @param hashSize hashSize is the size of the hashTable. It is the mod factor.
 * @param probValue Probing value used to determine hash value in quadratic probing.
 * @return Value of the slot calculated.
 */
long int hashFunction2(long int key, long int hashSize, long int probValue);

/**
 * @brief Hash Function returning the slot value.
 *
 * Hash Function 1 calculates the slot of the key using average method. It calculates the average
 * of the slot values given by hashFunction1 and hashFunction2.
 *
 * @param key Key to be stored.
 * @param hashSize hashSize is the size of the hashTable. It is the mod factor.
 * @param probValue Probing value used to determine hash value in quadratic probing.
 * @return Value of the slot calculated.
 */
long int hashFunction3(long int key, long int hashSize, long int probValue);

/**
 * @brief Hash Function returning the slot value.
 *
 * Hash Function returns the value of slot by the hash function that is currently in use. This function is
 * used in all the operation. If you want to change the hash function, just select a different hash function
 * in this function.
 * @param key Key to be stored.
 * @param hashSize hashSize is the size of the hashTable. It is the mod factor.
 * @param probValue Probing value used to determine hash value in quadratic probing.
 * @return Value of the slot calculated.
 */
long int hashFunction(long int key, long int hashSize, long int probValue);


/**
 * @brief Returns the number of collisions of the hash table.
 *
 * It returns the number of collisions occurred in the insertion process.
 *
 * @param hashTable hashTable whose  number of collisions is to be returned.
 * @return Number of collisions of given hash table.
 */
long int getHashCollisions(HashTable_t *hashTable);

/**
 * @brief Searches a key from the hash table.
 *
 * This function first searches the key in the hash table and returns the slot value. If the search is unsuccessful
 * then -1 is returned.
 *
 * @param hashTable hashTable where key is to be searched.
 * @param key Key to be searched
 * @return void. Returns the slot value if search is successful, else -1.
 */
long int hashSearch(HashTable_t *hashTable, long int key);


/**
 * @brief Deletes a key from the hash table.
 *
 * This function first searches the key in the hash table then deletes if found. By deleting it means overwriting
 * the slot value with INF. If key is not found then error message is displayed.
 *
 * @param hashTable hashTable where key is to be deleted.
 * @param key Key to be deleted.
 * @return void. Returns nothing.
 */
void hashDelete(HashTable_t *hashTable, long int key);


/**
 * @brief Inserts a key into a hash table.
 *
 * It searches for a slot using hash function for the key and then inserts a key into the hashTable. If not slot is
 * found then it displays the error message of hash table being overflowed.
 * @param hashTable hashTable where key is to be inserted.
 * @param key Key to be inserted.
 * @return void. Returns nothing.
 */
void hashInsert(HashTable_t *hashTable, long int key);

#endif /* HASHTABLE_H_ */

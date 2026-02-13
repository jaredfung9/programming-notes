#include "hashtable.h"
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

//const static double LOAD_FACTOR = 0.5F; 
static const size_t DEFAULT_TABLE_SIZE = 256;
static const size_t MAX_STRING_LENGTH = 1024;

typedef struct HashTable 
{
	size_t current_item_count;
	size_t maximum_item_count;
	char** data;
}HashTable;

uint64_t fnv1a(void* data, size_t number_of_bytes)
{
	uint64_t FNV_offset_basis = 0xcbf29ce484222325;
	uint64_t FNV_prime = 0x100000001b3;
	uint64_t hash = FNV_offset_basis;

	char* bytes = (char*) data;
	for (unsigned int i = 0; i < number_of_bytes; i++)
	{
		hash = hash * FNV_prime;
		hash = hash ^ bytes[i];
	}
	return hash;
}

HashTable* init_hashtable(void)
{
	HashTable* table = malloc(sizeof(HashTable));
	table->current_item_count = 0;
	table->maximum_item_count = DEFAULT_TABLE_SIZE;
	table->data = calloc(table->maximum_item_count, sizeof(char*));
	return table;
}

void free_hashtable(HashTable* table)
{
	for (unsigned int i = 0; i < table->maximum_item_count; i++) {
		char* entry = table->data[i];
		if (entry != NULL)
		{
			free(entry);
		}
	}
	free(table->data);
	free(table);
}

uint64_t getBucket(HashTable* table, char* string)
{
	uint64_t hash = fnv1a((void*) string, strnlen(string, MAX_STRING_LENGTH));
	return hash % table->maximum_item_count;
}

/*
TODO: Resize Table based on load factor
TODO: Quadratic Probing
*/
void insert(HashTable* table, char* insertion_string) {
	size_t length = strnlen(insertion_string, MAX_STRING_LENGTH);
	uint64_t bucket = getBucket(table, insertion_string);
	table->data[bucket] = insertion_string;
}

/*
TODO: FAILURE CASE!
TODO: Quadratic Probing
*/
char* lookup(HashTable* table, char* target_string)
{
	size_t length = strnlen(target_string, MAX_STRING_LENGTH);
	uint64_t bucket = getBucket(table, target_string); 
	return table->data[bucket];
}

/*
TODO: Entry deletion function
*/

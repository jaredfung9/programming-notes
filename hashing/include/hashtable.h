#ifndef HASHING_HASHTABLE_H
#define HASHING_HASHTABLE_H

typedef struct HashTable HashTable;
HashTable* init_hashtable(void);
void free_hashtable(HashTable* table);
char* lookup(HashTable* table, char* target_string);
void insert(HashTable* table, char* insertion_string);
void del(HashTable* table, char* deletion_string); 

#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hashtable.h"
int main()
{
	HashTable* table = init_hashtable();
	char* str = malloc(sizeof(char)*6);
	strncpy(str, "world", 5);
	insert(table, str);
	char* res = lookup(table, str);
	free_hashtable(table);
	return 0;
}

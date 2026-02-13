#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hashtable.h"
int main()
{
	HashTable* table = init_hashtable();
	char* str = malloc(sizeof(char)*7);
	strncpy(str, "world", 7);
	insert(table, str);
	char* res = lookup(table, str);
	printf("%s\n", res);
	free_hashtable(table);
	return 0;
}

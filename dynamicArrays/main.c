#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
        int *items;
        size_t count;
        size_t capacity;
} intArray;

int arrayAppend(intArray *array, int item)
{
        if (array->count >= array->capacity) {
                if (array->capacity == 0) array->capacity = 256;
                else array->capacity *=2;
                array->items = realloc(array->items, array->capacity*sizeof(array->items[0]));
                if (array->items == NULL) return -1;
        }
        array->items[array->count++] = item;
        return 0;
}

/*
 * Returns -1 if i is out of ARRAY's allocation range.
 */
int arraySet(intArray *array, int i, int item)
{
        if (array->capacity <= i) return -1;
        else array->items[i] = item;
        return 0;
}

int main()
{
        intArray xs = {0};
        for (int x = 0;  x < 10; ++x) {
                arrayAppend(&xs, x + 1);
        }
        arraySet(&xs, 3, 52);
        for (size_t i = 0; i < xs.count; ++i) printf("%d\n", xs.items[i]);
        return 0;
}

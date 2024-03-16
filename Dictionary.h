#pragma once
#include <stdlib.h>
#include <stddef.h>

#define GROW_CAPACITY(oldCapacity) ((old_capacity) < 8 ? 8 : (oldCapacity) * 2)
#define GROW_ARRAY(type, pointer, newSize) (*type)reallocate(type* pointer, sizeof(type) * newSize)
#define FREE_ARRAY(pointer) reallocate((pointer), 0)


typedef struct {
	int *keys;
	int *values;
	int count;
	int capacity;
}Dictionary;

void initDictionary(Dictionary* dictionary);
void writeDictionary(Dictionary* dictionary, int lineNum);
void freeDictionary(Dictionary* dictionary);
void *reallocate(void *pointer, size_t newSize);

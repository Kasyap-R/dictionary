#include "Dictionary.h"


void initDictionary(Dictionary* dictionary) {
	dictionary->keys = NULL;
	dictionary->values = NULL;
	dictionary->count = 0;
	dictionary->capacity=0;
}

void writeDictionary(Dictionary *dictionary, int lineNum) {
	if(dictionary->capacity < dictionary->count + 1) {
		int oldCapacity = dictionary->capacity;
		dictionary->capacity = GROW_CAPACITY(oldCapacity);
		dictionary->keys = GROW_ARRAY(int, dictionary->keys, dictionary->capacity);
		dictionary->values = GROW_ARRAY(int, dictionary->values, dictionary->capacity);

	}

	for(int i = 0; i < dictionary->count; i++) {
		if(dictionary->keys[i] == lineNum) {
			dictionary->values[i] += 1;
			return;
		}
	}

	dictionary->keys[dictionary->count] = lineNum;
	dictionary->count += 1;
}

void freeDictionary(Dictionary *dictionary){
	FREE_ARRAY(dictionary->keys);
	FREE_ARRAY(dictionary->values);
	initDictionary(dictionary);
}

void* reallocate(void *pointer, size_t newSize) {
	if (newSize == 0) {
		free(pointer);
		return NULL;
	}

	void* result = realloc(pointer, newSize);
	return result;
}

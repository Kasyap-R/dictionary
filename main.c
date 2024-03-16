#include <stdlib.h>
#include <stdio.h>
#include "Dictionary.h"


int main() {
	Dictionary *dictionary;
	initDictionary(dictionary);
	writeDictionary(dictionary, 3);
	writeDictionary(dictionary, 3);
	writeDictionary(dictionary, 4);
	writeDictionary(dictionary, 4);
	for(int i = 0; i < dictionary->count; i++) {
		printf("Dictionary Line: %d\n ", dictionary->keys[i]);
		printf("Line Occurence: %d\n ", dictionary->values[i]);
	}
	return 0;
}


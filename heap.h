//
// Created by Uriel Barbosa Pinheiro on 2019-08-24.
//

#ifndef UP_DOWN_CHALLENGE_HEAP_H
#define UP_DOWN_CHALLENGE_HEAP_H

#include "state.h"
#include "aStar.h"

typedef int heapKeyType;
typedef State *heapValueType;

typedef struct {
    heapKeyType key;
    heapValueType value;
} HeapElement;

typedef struct {
    HeapElement element[MAXIMUMOPENCLOSED];
    int size;
} Heap;

void heap_ascending_filtering(Heap *h, int i);
void heap_descending_filtering(Heap *h, int i);
void heap_init(Heap *h);
bool heap_is_empty(Heap *h);
bool heap_insert(HeapElement element, Heap *h);
bool heap_delete(HeapElement *minimum, Heap *h);
void head_decrease_key(HeapElement element, heapKeyType newValue, Heap *h);
void heap_increase_key(int position, heapKeyType increment, Heap *h);

#endif //UP_DOWN_CHALLENGE_HEAP_H

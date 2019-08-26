//
// Created by Uriel Barbosa Pinheiro on 2019-08-24.
//

#include "heap.h"
#include <stdbool.h>

void heap_ascending_filtering(Heap *h, int i) {
    while(h->element[i / 2].key > h->element[i].key){
        i = i/2;
    }
}

void heap_descending_filtering(Heap *h, int i) {
    int endFiltering = 0;
    int children;
    while(2*i <= h->size && (!endFiltering)){
        children = 2 * i;
        if(children != h->size){
            if(h->element[children + 1].key < h->element[children].key)
                children++;
        }
        if(h->element[h->size].key > h->element[children].key){
            i = children;
        }
        else
            endFiltering = 1;
    }
}
void heap_init(Heap *h) {
    h->size = 0;
}
bool heap_is_empty(Heap *h) {
    if(h->size == 0) {
        return true;
    }
    else {
        return false;
    }
}

bool heap_insert(HeapElement element, Heap *h) {
    int i;
    HeapElement aux;

    if (h->size == MAXIMUMOPENCLOSED)
        return false;
    h->size++;
    i = h->size;
    h->element[i] = element;
    while(h->element[i / 2].key > h->element[i].key) {
        aux = h->element[i];
        h->element[i] = h->element[i / 2];
        h->element[i / 2] = aux;
        i = i/2;
    }
    h->element[i].key = element.key;
    h->element[i].value = element.value;
    return true;
}

bool heap_delete(HeapElement *minimum, Heap *h) {
    int endFiltering = 0;
    int children;
    int i;
    HeapElement last;
    last.key = h->element[h->size].key;
    last.value = h->element[h->size].value;

    if(heap_is_empty(h) == true)
        return false;
    minimum->key = h->element[1].key;
    minimum->value = h->element[1].value;
    h->size--;
    i = 1;

    while(2*i <= h->size && (!endFiltering)){
        children = 2 * i;
        if(children != h->size){
            if(h->element[children + 1].key < h->element[children].key)
                children++;
        }
        if(h->element[h->size].key > h->element[children].key){
            h->element[i].key = h->element[children].key;
            h->element[i].value = h->element[children].value;
            i = children;
        }
        else
            endFiltering = 1;
    }

    h->element[i].key = last.key;
    h->element[i].value = last.value;

    return true;
}

void head_decrease_key(HeapElement element, heapKeyType newValue, Heap *h) {
    int i, tam;
    HeapElement aux[MAXIMUMOPENCLOSED];
    HeapElement elementAux;

    tam = h->size;
    for(i = 0; i < tam; i++) {
        heap_delete(&elementAux, h);
        if(elementAux.value == element.value) {
            elementAux.key = newValue;
        }
        aux[i] = elementAux;
    }

    for(i = 0; i < tam; i++) {
        elementAux = aux[i];
        heap_insert(elementAux, h);
    }
}
void heap_increase_key(int position, heapKeyType increment, Heap *h) {
    h->element[position].key += increment;
    heap_descending_filtering(h, position);
}
// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train() : countOp(0), first(nullptr) {}

void Train::addCar(bool light) {
    Car* newCar = new Car{light, nullptr, nullptr};
    
    if (first == nullptr) {
        first = newCar;
        newCar->next = newCar;
        newCar->prev = newCar;
    } else {
        Car* last = first->prev;
        last->next = newCar;
        newCar->prev = last;
        newCar->next = first;
        first->prev = newCar;
    }
}

int Train::getLength() {
    if (first == nullptr) return 0;
    
    countOp = 0;
    
    int length = 0;
    Car* current = first;
    
    do {
        length++;
        current = current->next;
        countOp++;
    } while (current != first);
    
    return length;
}

int Train::getOpCount() {
    return countOp;
}

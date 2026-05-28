// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train() : countOp(0), first(nullptr) {}

void Train::addCar(bool light) {
    Car* newCar = new Car{light, nullptr, nullptr};
    if (!first) {
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
    if (!first) return 0;

    countOp = 0;

    int len = 0;
    Car* ptr = first;

    if (!first->light) {
        do {
            len++;
            ptr = ptr->next;
            countOp++;
        } while (ptr != first);

        ptr = first;
        do {
            ptr = ptr->next;
            countOp++;
        } while (ptr != first);
    } else {
        do {
            len++;
            Car* p = ptr;
            do {
                p = p->next;
                countOp++;
            } while (p != first);
            ptr = ptr->next;
        } while (ptr != first);
    }

    return len;
}

int Train::getOpCount() {
    return countOp;
}

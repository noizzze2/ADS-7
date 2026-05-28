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

    if (!first->light) {
        first->light = true;
        int length = 1;
        const Car* current = first->next;
        countOp++;
        while (current != first) {
            length++;
            current = current->next;
            countOp++;
        }
        current = first->next;
        countOp++;
        while (current != first) {
            current = current->next;
            countOp++;
        }
        return length;
    } else {
        first->light = false;
        int step = 1;
        while (true) {
            const Car* current = first;
            for (int i = 0; i < step; i++) {
                current = current->next;
                countOp++;
            }
            if (!current->light) {
                for (int i = 0; i < step; i++) {
                    current = current->next;
                    countOp++;
                }
                return step;
            }
            for (int i = 0; i < step; i++) {
                current = current->next;
                countOp++;
            }
            step++;
        }
    }
}

int Train::getOpCount() {
    return countOp;
}

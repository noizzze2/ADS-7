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
        // Все выключены — 2 прохода
        int length = 0;
        const Car* current = first;
        do {
            length++;
            current = current->next;
            countOp++;
        } while (current != first);

        current = first;
        do {
            current = current->next;
            countOp++;
        } while (current != first);

        return length;
    } else {
        // Все включены — нерациональный способ (O(n²))
        int length = 0;
        Car* current = first;
        do {
            length++;
            const Car* temp = current;
            do {
                temp = temp->next;
                countOp++;
            } while (temp != first);
            current = current->next;
        } while (current != first);

        return length;
    }
}

int Train::getOpCount() {
    return countOp;
}

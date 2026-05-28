// Copyright 2022 NNTU-CS
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "train.h"

int main() {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    std::cout << "n off on random" << std::endl;

    for (int n = 10; n <= 100; n += 10) {
        Train t1;
        for (int i = 0; i < n; i++) t1.addCar(false);
        t1.getLength();
        int off = t1.getOpCount();

        Train t2;
        for (int i = 0; i < n; i++) t2.addCar(true);
        t2.getLength();
        int on = t2.getOpCount();

        Train t3;
        for (int i = 0; i < n; i++) t3.addCar(std::rand() % 2);
        t3.getLength();
        int rnd = t3.getOpCount();

        std::cout << n << " " << off << " " << on << " " << rnd << std::endl;
    }

    return 0;
}

// Copyright 2022 NNTU-CS
#include <cstdlib>
#include <ctime>
#include <iostream>
#include "train.h"

int main() {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    std::cout << "n\tfalse\ttrue\trandom\n";

    for (int n = 2; n <= 100; ++n) {
        int resFalse, resTrue, resRand;

        {
            Train train;
            for (int i = 0; i < n; ++i) {
                train.addCar(false);
            }
            train.getLength();
            resFalse = train.getOpCount();
        }

        {
            Train train;
            for (int i = 0; i < n; ++i) {
                train.addCar(true);
            }
            train.getLength();
            resTrue = train.getOpCount();
        }

        {
            Train train;
            for (int i = 0; i < n; ++i) {
                train.addCar(std::rand() % 2);
            }
            train.getLength();
            resRand = train.getOpCount();
        }

        std::cout << n << "\t" << resFalse << "\t" << resTrue << "\t" << resRand << "\n";
    }

    return 0;
}

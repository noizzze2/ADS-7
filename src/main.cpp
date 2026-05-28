// Copyright 2022 NNTU-CS
#include <iostream>
#include "train.h"
#include <cstdlib>
#include <ctime>

int main() {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    std::cout << "n off on random" << std::endl;

    for (int n = 10; n <= 100; n += 10) {
        Train trainOff;
        for (int i = 0; i < n; i++) {
            trainOff.addCar(false);
        }
        trainOff.getLength();
        int offOps = trainOff.getOpCount();

        Train trainOn;
        for (int i = 0; i < n; i++) {
            trainOn.addCar(true);
        }
        trainOn.getLength();
        int onOps = trainOn.getOpCount();

        Train trainRandom;
        for (int i = 0; i < n; i++) {
            bool light = std::rand() % 2;
            trainRandom.addCar(light);
        }
        trainRandom.getLength();
        int randomOps = trainRandom.getOpCount();

        std::cout << n << " " << offOps << " " 
                  << onOps << " " << randomOps << std::endl;
    }

    return 0;
}

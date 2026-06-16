#include "array_task.hpp"

#include <iomanip>
#include <iostream>

int main() {
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Lab 5, variant 4\n";

    try {
        ArrayTask validArray({0.0, -5.0, 4.5, 0.0, 7.0, -1.5, 2.0, -3.0, 0.0, 8.0, -6.0, 1.0});
        std::cout << validArray.sourceArrayAsString() << '\n';
        std::cout << "Minimum element: " << validArray.minElement() << '\n';
        std::cout << "Sum between first and last positive elements: "
                  << validArray.sumBetweenFirstAndLastPositive() << '\n';
        validArray.moveZerosToFront();
        std::cout << validArray.transformedArrayAsString() << '\n';
        std::cout << "Element at index 3: " << validArray.at(3) << '\n';
    } catch (const std::exception& error) {
        std::cout << "Unexpected error in valid case: " << error.what() << '\n';
    }

    try {
        ArrayTask wrongSize({1.0, 2.0, 3.0});
        std::cout << wrongSize.sourceArrayAsString() << '\n';
    } catch (const std::exception& error) {
        std::cout << "Handled size exception: " << error.what() << '\n';
    }

    try {
        ArrayTask noPositive({0.0, -1.0, -2.0, 0.0, -3.0, -4.0, 0.0, -5.0, -6.0, -7.0, -8.0, -9.0});
        std::cout << noPositive.sumBetweenFirstAndLastPositive() << '\n';
    } catch (const PositiveRangeException& error) {
        std::cout << "Handled custom exception: " << error.what() << '\n';
    }

    try {
        ArrayTask outOfRangeArray({1.0, 0.0, 2.0, 0.0, 3.0, 0.0, 4.0, 0.0, 5.0, 0.0, 6.0, 0.0});
        std::cout << outOfRangeArray.at(20) << '\n';
    } catch (const std::exception& error) {
        std::cout << "Handled out_of_range exception: " << error.what() << '\n';
    }

    return 0;
}


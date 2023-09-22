#include <iostream>
#include <cmath>

double calculateChiSquare(int observed[], int expected[], int size) {
    double chiSquare = 0.0;

    for (int i = 0; i < size; ++i) {
        double diff = observed[i] - expected[i];
        chiSquare += (diff * diff) / expected[i];
    }

    return chiSquare;
}

int main() {
    const int size = 3;
    int observed[size] = {30, 45, 25};
    int expected[size] = {40, 40, 20};

    double chiSquare = calculateChiSquare(observed, expected, size);

    // Degrees of freedom is (number of categories - 1)
    int degreesOfFreedom = size - 1;

    std::cout << "Chi-Square Value: " << chiSquare << std::endl;
    std::cout << "Degrees of Freedom: " << degreesOfFreedom << std::endl;

    // You can compare the chi-square value with a critical value from a chi-square distribution table
    // and perform a hypothesis test to determine if the observed values deviate significantly
    // from the expected values. You'll need to define a significance level and critical value
    // for your specific hypothesis test.

    return 0;
}
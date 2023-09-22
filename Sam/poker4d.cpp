#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
int generateRandomNumber()
{
    return rand() % 9000 + 1000; // Generates a 4-digit number (1000 to 9999)
}

void countPokerHandPatterns(int sequence[], int length, int patternCount[])
{
    for (int i = 0; i < length; ++i)
    {
        int pokerHandPattern = sequence[i] % 100; // Extract the last two digits as a pattern
        patternCount[pokerHandPattern]++;
    }
}
double calculateChiSquare(int observed[], int expected[], int length)
{
    double chiSquare = 0.0;

    for (int i = 0; i < length; ++i)
    {
        double diff = observed[i] - expected[i];
        chiSquare += (diff * diff) / expected[i];
    }

    return chiSquare;
}

int main()
{
    // Seed the random number generator
    srand(static_cast<unsigned int>(time(nullptr)));

    const int sequenceLength = 1000; // You can adjust the length as needed
    int sequence[sequenceLength];

    // Generate a random sequence of 4-digit numbers
    for (int i = 0; i < sequenceLength; ++i)
    {
        sequence[i] = generateRandomNumber();
    }

    // Initialize an array to count the frequency of each poker hand pattern
    const int numPatterns = 100; // There are 100 possible patterns (00 to 99)
    int patternCount[numPatterns] = {0};

    // Count the frequency of each poker hand pattern
    countPokerHandPatterns(sequence, sequenceLength, patternCount);

    // Calculate expected frequencies (assuming uniform distribution)
    int expectedFrequency = sequenceLength / numPatterns;
    int expected[numPatterns];
    for (int i = 0; i < numPatterns; ++i)
    {
        expected[i] = expectedFrequency;
    }
    double chiSquare = calculateChiSquare(patternCount, expected, numPatterns - 1); // -1 for degrees of 
    std::cout << "Chi-Square Value: " << chiSquare << std::endl;
    return 0;
}
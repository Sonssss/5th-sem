#include <iostream>
#include <cstdlib>
#include <ctime>

int generateRandomNumber()
{
    return rand() % 900 + 100; // Generates a 3-digit number (100 to 999)
}

// Function to count the frequency of each poker hand pattern
void countPokerHandPatterns(int sequence[], int length, int patternCount[])
{
    for (int i = 0; i < length; ++i)
    {
        int pokerHandPattern = sequence[i] % 100; // Extract the last two digits as a pattern
        patternCount[pokerHandPattern]++;
    }
}

// Function to calculate the Chi-Square statistic for randomness
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

    // Generate a random sequence of 3-digit numbers
    for (int i = 0; i < sequenceLength; ++i)
    {
        sequence[i] = generateRandomNumber();
    }
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
    double chiSquare = calculateChiSquare(patternCount, expected, numPatterns - 1); // -1 for degrees of freedom


    std::cout << "Chi-Square Value: " << chiSquare << std::endl;

    return 0;
}
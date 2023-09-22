#include <iostream>
#include <cstdlib>
#include <ctime>

// Function to generate a random sequence of numbers
void generateRandomSequence(int sequence[], int length, int max_value)
{
    for (int i = 0; i < length; ++i)
    {
        sequence[i] = rand() % max_value; // Adjust the range as needed
    }
}

// Function to perform the Gap test for independence
bool performGapTest(const int sequence[], int length, int max_gap)
{
    for (int i = 1; i < length; ++i)
    {
        int gap = abs(sequence[i] - sequence[i - 1]);
        if (gap > max_gap)
        {
            return false; // If any gap is greater than the threshold, it's not independent
        }
    }
    return true;
}

int main()
{
    // Seed the random number generator
    srand(static_cast<unsigned int>(time(nullptr)));

    const int length = 100;
    int sequence[length];

    // Generate a random sequence of numbers (you can adjust the range)
    int max_value = 100;
    generateRandomSequence(sequence, length, max_value);

    // Set the maximum gap threshold for independence testing
    int max_gap = 20;

    // Perform the Gap test
    bool isIndependent = performGapTest(sequence, length, max_gap);

    if (isIndependent)
    {
        std::cout << "The sequence appears to be independent." << std::endl;
    }
    else
    {
        std::cout << "The sequence is not independent." << std::endl;
    }

    return 0;
}
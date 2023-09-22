#include <iostream>
#include <cmath>

double calculateDurbinWatson(double residuals[], int n)
{
    double d = 0.0;

    for (int i = 1; i < n; ++i)
    {
        double diff = residuals[i] - residuals[i - 1];
        d += diff * diff;
    }

    double numerator = 0.0;
    for (int i = 0; i < n; ++i)
    {
        numerator += residuals[i] * residuals[i];
    }

    double denominator = numerator + d;

    return d / denominator;
}

int main()
{
    const int n = 5;
    double residuals[n] = {1.2, 0.8, -0.5, -0.3, 0.7};

    double durbinWatson = calculateDurbinWatson(residuals, n);

    std::cout << "Autocorrelation Statistic: " << durbinWatson << std::endl;


    return 0;
}
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
int count=1;

int partition(int arr[], int low, int high)
{
    int randomIndex = low + rand() % (high - low + 1);
    swap(arr[randomIndex], arr[high]);

    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        count++;
        if (arr[j] <= pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pivotIndex = partition(arr, low, high);

        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

int main()
{
    srand(time(0));

    int arr[] = {12, 11, 10, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    // cout << "Program By: Sagar Thapa "<<endl;

    cout << "Original Array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " "; 
    }

    quickSort(arr, 0, n - 1);

    cout << "\nSorted Array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout<<"\n The time complexity : "<<count<<endl;

    return 0;
}
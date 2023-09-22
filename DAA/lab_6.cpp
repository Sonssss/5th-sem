#include <iostream>


int countq=1, countm=1;

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    { 
        countq++;
        if (arr[j] <= pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
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

void merge(int arr[], int left, int mid, int right)
{
    int leftCount = mid - left + 1;
    int rightCount = right - mid;

    int *leftArray = new int[leftCount];
    int *rightArray = new int[rightCount];

    for (int i = 0; i < leftCount; i++)
    {
        leftArray[i] = arr[left + i];
    }
    for (int i = 0; i < rightCount; i++)
    {
        rightArray[i] = arr[mid + 1 + i];
    }

    int i = 0, j = 0, k = left;
    while (i < leftCount && j < rightCount)
    { countm++;
        if (leftArray[i] <= rightArray[j])
        {
            arr[k] = leftArray[i];
            i++;
        }
        else
        {
            arr[k] = rightArray[j];
            j++;
        }
        k++;
    }

    while (i < leftCount)
    {
        arr[k] = leftArray[i];
        i++;
        k++;
    }

    while (j < rightCount)
    {
        arr[k] = rightArray[j];
        j++;
        k++;
    }

    delete[] leftArray;
    delete[] rightArray;
}

// Merge Sort algorithm
void mergeSort(int arr[], int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main()
{
    int arr[] = {12, 11, 13, 15, 6, 7};
    int arrSize = sizeof(arr) / sizeof(arr[0]);

    int arr1[] = {12, 11, 13, 15, 6, 7};
    int arrSize1 = sizeof(arr1) / sizeof(arr1[0]);

    // std::cout<<"Program By : Sagar Thapa"<<std::endl;
    
    std::cout<<"Quick sort"<<std::endl;

    std::cout << "Original array: ";
    for (int i = 0; i < arrSize; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    quickSort(arr, 0, arrSize - 1); 

    std::cout << "Sorted array: ";
    for (int i = 0; i < arrSize; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Time complexity of Quick sort is :" << countq << std::endl<<std::endl;

    std::cout << "Merge sort" << std::endl;

    std::cout << "Original array: ";
    for (int i = 0; i < arrSize1; i++)
    {
        std::cout << arr1[i] << " ";
    }
    std::cout << std::endl;


    mergeSort(arr1, 0, arrSize1 - 1);

    std::cout << "Sorted array: ";
    for (int i = 0; i < arrSize1; i++)
    {
        std::cout << arr1[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Time complexity of Merge sort is :" << countm << std::endl;

    return 0;
}

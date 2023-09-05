#include <iostream>
using namespace std;

int count1 = 1, count2 = 1, count3= 1;

void BubbleSort(int A[],int n){
    int temp =0,i,j;
    for( i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            count1++;

            if(A[j]>A[j+1])
            {
                temp =A[j];
                A[j]=A[j+1];
                A[j+1]=temp;
            }
        }
    }

    cout<<"the bubble sort is :"<<endl;
    for(i=0;i<n;i++)
        cout<<A[i]<<endl;
    cout<<"the time complexity is :"<<count1<<endl;
}

void SelectionSort(int A1[], int n)
{
    int i, minValue = 0, minIndex = 0, j;
    for (i = 0; i < n - 1; i++)
    {

        minIndex = i;
        minValue = A1[i];
        for (j = i + 1; j < n; j++)
        {
            count2++;

            if (A1[j] < minValue)
            {
                minIndex = j;
                minValue = A1[j];
            }
        }
        swap(A1[i], A1[minIndex]);
    }
    cout << "the selection sort is :" << endl;
    for (i = 0; i < n; i++)
        cout << A1[i] << endl;
    cout << "the time complexity is :" << count2<<endl;
}

void InsertionSort(int A2[], int n)
{
    int i, j, key = 0;
    for (i = 1; i < n; i++)
    {
        key = A2[i];
        for (j = i - 1; j >= 0 && A2[j] > key; j--)
        {
        count3++;

            A2[j + 1] = A2[j];
        }
        A2[j + 1] = key;
    }

    cout << "the Insertion sort is :" << endl;
    for (i = 0; i < n; i++)
        cout << A2[i] << endl;
    cout << "the time complexity is :" << count3<<endl;
}

int main()
{
    int A[] = {4, 7, 2, 5, 3, 1, 8, 6}, n = 8, A1[] = {32, 24, 15, 30, 46, 54, 12, 16}, A2[] = {32, 24, 15, 30, 46, 54, 12, 16};
    
    BubbleSort(A,n);
    SelectionSort(A1, n);
    InsertionSort(A2, n);
}
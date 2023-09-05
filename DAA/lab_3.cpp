//linear and binary search


#include <iostream>
using namespace std;
int counts = 1, countl = 1;
int linear(int a[], int search, int n)
{

    int i;
    for (i = 0; i < n; i++)
    {
        countl++;
        if (a[i] == search)
        {
           
            return 1;
        }
    }
    return 0;
}

int binary(int a[], int search, int n)
{

    int low = 0, high = n;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (a[mid] == search)
        {
            counts++;
            return 1;
        }
        if (a[mid] < search)
        {
            counts++;
            low = mid + 1;
        }
        else
        {
            counts++;
            high = mid - 1;
        }
    }
    counts++;
    return 0;
}

int main()
{
    int n, i, a[100], search;
    cout << "Program by: Soniya Pandey" << endl;
    cout << "enter the no of and array";
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cout << "a[" << i << "] :" << endl;
        cin >> a[i];
    }
    cout << "enter the number you want to search :" << endl;
    cin >> search;
    cout << "In linear search :" << linear(a, search, n)<<endl;
    cout<<"The time complexity of linear search is :"<<countl<<endl;
    cout << "In binary search :" << binary(a, search, n)<<endl;
    cout << "The time complexity of binary search is :" << counts << endl;
}
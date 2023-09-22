#include <iostream>
using namespace std;
int count=1;

int binarySearch(int array[], int low, int high, int number_to_search_for) {

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (number_to_search_for == array[mid]){
            count++;
            return mid;
        }

        if (number_to_search_for > array[mid]){
            count++;
            low = mid + 1;
        }
      
        if (number_to_search_for < array[mid]){
            count++;
            high = mid - 1;
        }

    }

  return -1;
}

int main(void) {
  int arrayOfNum[] = {2,4,7,9,10,13,20};
  
  int n = sizeof(arrayOfNum) / sizeof(arrayOfNum[0]);
  
  int result = binarySearch(arrayOfNum, 0, n - 1, 2);
  if (result == -1){
      printf("Element doesn't exist in the array");
      printf("\nTime complexity: %d", count);
  }
  else{
      printf("The index of the element is %d", result);
      printf("\nTime complexity: %d", count);
  }
  
  // The index of the element is 5
}
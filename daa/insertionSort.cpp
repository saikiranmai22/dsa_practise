#include<iostream>
using namespace std;

// Function to perform insertion sort
void insertionSort(int arr[], int n) {
    
    for (int i = 1; i < n; i++) {
        int key = arr[i];  // The element to be inserted
        int j = i - 1;     // The index to compare with

        // Move elements of arr[0..i-1] that are greater than key
        // to one position ahead of their current position
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        // Place the key in the correct position
        arr[j + 1] = key;
    }
}
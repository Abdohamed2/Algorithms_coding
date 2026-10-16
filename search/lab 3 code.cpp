#include <iostream>

using namespace std;

// Function Prototypes
int linearSearch(const int[], int, int, int&);
int binarySearch(const int[], int, int, int&);

int main() {
    // Array of 20 integers (sorted for Binary Search compatibility)
    const int SIZE = 20;
    int data[SIZE] = {12, 18, 23, 34, 45, 56, 62, 71, 80, 88,
                      92, 99, 105, 120, 135, 140, 150, 166, 189, 201};

    //int target = 166; // The value we are looking for
    int target = 201;
    int linearComp = 0;
    int binaryComp = 0;

    cout << "Searching for value: " << target << endl;
    cout << "------------------------------------" << endl;

    // Perform Linear Search
    int linearResult = linearSearch(data, SIZE, target, linearComp);

    // Perform Binary Search
    int binaryResult = binarySearch(data, SIZE, target, binaryComp);

    // Display Results
    if (linearResult != -1) {
        cout << "Linear Search comparisons: " << linearComp << endl;
        cout << "Binary Search comparisons: " << binaryComp << endl;
    } else {
        cout << "Value not found in the array." << endl;
    }

    return 0;
}

// Linear Search: Checks every element from start to finish
int linearSearch(const int arr[], int size, int value, int &count) {
    for (int i = 0; i < size; i++) {
        count++; // Increment comparison count
        if (arr[i] == value) {
            return i;
        }
    }
    return -1;
}

// Binary Search: Divides the search range in half each step
int binarySearch(const int arr[], int size, int value, int &count) {
    int first = 0,
        last = size - 1,
        middle;

    while (first <= last) {
        count++; // Increment comparison count
        middle = (first + last) / 2;

        if (arr[middle] == value) {
            return middle;
        } else if (arr[middle] > value) {
            last = middle - 1;
        } else {
            first = middle + 1;
        }
    }
    return -1;
}

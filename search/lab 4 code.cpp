#include <iostream> // For printf
using namespace std;
// 2D Array: [Row][Column]
// Column 0: Letter (Sorted for Binary Search)
// Column 1: Code (Used for Sequential Search)
const char lookupTable[10][2] = {
    {'a', '#'}, {'c', '@'}, {'e', '%'}, {'g', '&'}, {'h', '*'},
    {'i', '('}, {'m', ')'}, {'r', '!'}, {'s', ','}, {'t', '='}
};

const int rows = 10;

// Binary Search for Encoding (Searching Column 0)
char binarySearchEncode(char target) {
    int low = 0;
    int high = rows - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        // Check middle element's letter
        if (lookupTable[mid][0] == target) {
            return lookupTable[mid][1]; // Found: Return the Code
        }

        if (lookupTable[mid][0] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return '?'; // Character not in table
}

// Sequential Search for Decoding (Searching Column 1)
char sequentialSearchDecode(char targetCode) {
    for (int i = 0; i < rows; i++) {
        // Linear check through symbols
        if (lookupTable[i][1] == targetCode) {
            return lookupTable[i][0]; // Found: Return the Letter
        }
    }
    return '?'; // Symbol not in table
}

int main() {
    const char* input = "thisisasecretmessage";
    char encoded[100] = {0};
    char decoded[100] = {0};

    //encoding
    cout<<"Input: "<<input<<endl;

    int i;
    for (i = 0; input[i] != '\0'; i++) {
        encoded[i] = binarySearchEncode(input[i]);
    }
    encoded[i] = '\0'; // Null-terminate the string
    cout<<"Encoded Output: "<<encoded<<endl;

    //decoding

    int j;
    for (j = 0; encoded[j] != '\0'; j++) {
        decoded[j] = sequentialSearchDecode(encoded[j]);
    }
    decoded[j] = '\0'; // Null-terminate the string
    cout<<"Decoded Output: "<< decoded<<endl;

    return 0;
}

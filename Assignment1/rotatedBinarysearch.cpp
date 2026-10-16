#include <iostream>
#include <vector>

using namespace std;

// Function to search in a rotated sorted array with duplicates
int searchRotatedArray(const vector<int> &arr, int target, int &comparisons)
{
    int left = 0;
    int right = arr.size() - 1;
    comparisons = 0;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        comparisons++; // arr[mid] == target
        if (arr[mid] == target)
        {
            return mid;
        }

        // Handle duplicates
        comparisons++; // arr[left] == arr[mid]
        bool isLeftEqual = (arr[left] == arr[mid]);
        bool isRightEqual = false;

        if (isLeftEqual)
        {
            comparisons++; // arr[mid] == arr[right]
            isRightEqual = (arr[mid] == arr[right]);
        }

        if (isLeftEqual && isRightEqual)
        {
            left++;
            right--;
            continue;
        }

        // Determine which half is sorted
        comparisons++; // arr[left] <= arr[mid]
        if (arr[left] <= arr[mid])
        {
            // Left half sorted
            comparisons++; // arr[left] <= target
            if (arr[left] <= target)
            {
                comparisons++; // target < arr[mid]
                if (target < arr[mid])
                {
                    right = mid - 1;
                }
                else
                {
                    left = mid + 1;
                }
            }
            else
            {
                left = mid + 1;
            }
        }
        else
        {
            // Right half sorted
            comparisons++; // arr[mid] < target
            if (arr[mid] < target)
            {
                comparisons++; // target <= arr[right]
                if (target <= arr[right])
                {
                    left = mid + 1;
                }
                else
                {
                    right = mid - 1;
                }
            }
            else
            {
                right = mid - 1;
            }
        }
    }
    return -1; // Not found
}

int main()
{
    vector<int> rotatedArray = {5, 6, 7, 7, 1, 2, 3, 4, 4};
    int target = 7;
    int comparisons = 0;

    int index = searchRotatedArray(rotatedArray, target, comparisons);

    cout << "--- Rotated Binary Search ---" << endl;
    if (index != -1)
    {
        cout << "Target " << target << " found at index: " << index << endl;
    }
    else
    {
        cout << "Target " << target << " not found in the array." << endl;
    }
    cout << "Total element-to-element comparisons: " << comparisons << endl;

    // Complexity notes (as required by assignment)
    cout << "Best Case Complexity: O(1)" << endl;
    cout << "Worst Case Complexity: O(n) due to duplicates" << endl;

    return 0;
}
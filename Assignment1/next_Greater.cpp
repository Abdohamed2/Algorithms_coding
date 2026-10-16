#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// Function to find the Next Greater Element for a circular array
vector<int> nextGreaterElements(const vector<int> &nums)
{
    int n = nums.size();
    vector<int> result(n, -1);
    stack<int> st; // stores indices

    for (int i = 0; i < 2 * n; i++)
    {
        int idx = i % n;
        while (!st.empty() && nums[st.top()] < nums[idx])
        {
            result[st.top()] = nums[idx];
            st.pop();
        }
        if (i < n)
            st.push(idx);
    }
    return result;
}

void printArray(const vector<int> &arr)
{
    cout << "[";
    for (int i = 0; i < (int)arr.size(); i++)
    {
        cout << arr[i];
        if (i < (int)arr.size() - 1)
            cout << ", ";
    }
    cout << "]\n";
}

int main()
{
    cout << "--- Next Greater Element (Circular Array) ---\n";

    vector<int> nums1 = {1, 2, 1};
    cout << "Input: ";
    printArray(nums1);
    auto res1 = nextGreaterElements(nums1);
    cout << "Output: ";
    printArray(res1);
    cout << endl;

    vector<int> nums2 = {1, 2, 3, 4, 3};
    cout << "Input: ";
    printArray(nums2);
    auto res2 = nextGreaterElements(nums2);
    cout << "Output: ";
    printArray(res2);

    return 0;
}
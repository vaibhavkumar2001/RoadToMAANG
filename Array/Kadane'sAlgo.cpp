#include <iostream>
#include <vector>
#include <climits> // For INT_MIN
using namespace std;

class Solution {
public:
    int maxSubarraySum(vector<int> &arr) {
        int n = arr.size();
        int sum = 0;
        int MaxSum = INT_MIN;

        for (int i = 0; i < n; i++) {
            sum += arr[i];
            MaxSum = max(MaxSum, sum);
            if (sum < 0) {
                sum = 0;
            }
        }

        return MaxSum;
    }
};

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter array elements: ";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    Solution sol;
    int result = sol.maxSubarraySum(arr);
    cout << "Maximum Subarray Sum is: " << result << endl;

    return 0;
}

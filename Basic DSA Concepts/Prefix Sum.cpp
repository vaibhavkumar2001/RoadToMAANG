#include <iostream>
#include <vector>
using namespace std;

// Function to compute prefix sum array
vector<int> findPrefixSum(vector<int>& nums) {
    int n = nums.size();
    vector<int> prefixSum(n);
    prefixSum[0] = nums[0];

    for(int i = 1; i < n; i++) {
        prefixSum[i] = prefixSum[i - 1] + nums[i];
    }

    return prefixSum;
}

int main() {
    vector<int> nums = {1, 2, 3, 4, 5};

    vector<int> result = findPrefixSum(nums);

    cout << "Prefix Sum Array: ";
    for(int val : result) {
        cout << val << " ";
    }

    return 0;
}

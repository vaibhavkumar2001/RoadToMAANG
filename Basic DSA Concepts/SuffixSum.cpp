#include <iostream>
#include <vector>
using namespace std;

vector<int> findSuffixSum(vector<int>& arr) {
    int n = arr.size();
    vector<int> suffixSum(n);
    
    suffixSum[n - 1] = arr[n - 1];  // Start from the last element

    for (int i = n - 2; i >= 0; i--) {
        suffixSum[i] = suffixSum[i + 1] + arr[i];
    }

    return suffixSum;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};

    vector<int> result = findSuffixSum(arr);

    cout << "Suffix Sum Array: ";
    for (int val : result) {
        cout << val << " ";
    }

    return 0;
}

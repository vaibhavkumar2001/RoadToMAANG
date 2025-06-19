#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> ans(nums.size(), 0);
        int even = 0;
        int odd = 1;

        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            if (num > 0) {
                ans[even] = num;
                even += 2;
            } else {
                ans[odd] = num;
                odd += 2;
            }
        }

        return ans;
    }
};

int main() {
    Solution sol;
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements (equal number of positive and negative): ";
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    vector<int> result = sol.rearrangeArray(nums);

    cout << "Rearranged array: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

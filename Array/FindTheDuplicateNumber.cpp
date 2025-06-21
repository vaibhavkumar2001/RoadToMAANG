#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        while (nums[0] != nums[nums[0]]) {
            swap(nums[0], nums[nums[0]]);
        }
        return nums[0];
    }
};

int main() {
    vector<int> nums = {3, 1, 3, 4, 2}; // Example input (duplicate is 3)
    
    Solution sol;
    int duplicate = sol.findDuplicate(nums);
    
    cout << "Duplicate number is: " << duplicate << endl;
    return 0;
}

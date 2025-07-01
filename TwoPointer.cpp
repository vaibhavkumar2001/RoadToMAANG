#include <iostream>
#include <vector>
using namespace std;

void sortZeroOne(vector<int>& nums) {
    int left = 0, right = nums.size() - 1;

    while (left < right) {
        // Move left forward if it's already at 0
        while (nums[left] == 0 && left < right) left++;

        // Move right backward if it's already at 1
        while (nums[right] == 1 && left < right) right--;

        // Swap if left is 1 and right is 0
        if (left < right) {
            swap(nums[left], nums[right]);
            left++;
            right--;
        }
    }
}

int main() {
    vector<int> arr = {0, 1, 1, 0, 1, 0, 0, 1};

    sortZeroOne(arr);

    cout << "Sorted array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

// 1 0 1 0 1 0 0 1
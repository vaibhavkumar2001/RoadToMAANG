#include<iostream>
#include<vector>
using namespace std;

class Solution {
  public:
    void reverseArray(vector<int> &arr) {
        int n = arr.size();
        int firstIndex = 0;
        int lastIndex = n - 1;

        while(firstIndex <= lastIndex) {
            swap(arr[firstIndex], arr[lastIndex]);
            firstIndex++;
            lastIndex--;
        }
    }
};

int main() {
    vector<int> arr = {1, 2, 3, 4};
    Solution obj;
    obj.reverseArray(arr);

    // Print reversed array
    for(int num : arr) {
        cout << num << " ";
    }
    return 0;
}

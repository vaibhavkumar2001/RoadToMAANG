//ISMEIN MAINE TWO POINTER + SLINDING WINDOW USE KRA H 

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maximumSumSubarray(vector<int>& arr, int k) {
        int n = arr.size();
        int l = 0;
        int r = k - 1;
        int Currsum = 0;
        int MaxSum = 0;

        //Maine Yahan pehli window ko process kiya h aur curr sum mein  add krdiya h ab mujhe window ko aage badhana h
        for(int i = 0; i <= r; i++) {
            Currsum += arr[i];
        }
        MaxSum = Currsum;

        // Slide the window
        while(r < n - 1) {
            // maine ab ek window mein se pehle number delete kr rha hoon 
            Currsum = Currsum - arr[l];
            l++;
            r++;
            //maine ab ek window mein naya number add kiya h
            Currsum = Currsum + arr[r];
            MaxSum = max(MaxSum, Currsum);
        }

        return MaxSum;
    }
};

int main() {
    Solution sol;
    vector<int> arr = {2, 1, 5, 1, 3, 2};
    int k = 3;
    int result = sol.maximumSumSubarray(arr, k);
    cout << "Maximum sum of subarray of size " << k << " is: " << result << endl;
    return 0;
}

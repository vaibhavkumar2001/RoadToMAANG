#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0;
        int j = k - 1;
        int sum = 0;
        for(int y = 0;y <= j;y++) {
            sum += nums[y];
        }
        int maxSum = sum;
        while(j < n - 1) {
            sum -= nums[i++];
            j++;
            sum += nums[j];
            maxSum = max(maxSum,sum);
        }
        double MaxAvg = maxSum / (double)k;
        return MaxAvg;
    }
};
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int n = arr.size();
        int l = 0;
        int r = k - 1;
        int sum = 0;
        int count = 0;
        for(int i = 0;i <= r;i++) {
            sum += arr[i];
        }
        if(sum / k >= threshold) {
            count++;
        }
        while(r < n - 1) {
            sum -= arr[l];
            l++;
            r++;
            sum += arr[r];
            if (sum / k >= threshold) {
                count++;
            }
        }
        return count;
    }
};

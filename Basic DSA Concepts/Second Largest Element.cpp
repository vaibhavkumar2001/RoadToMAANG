#include<bits/stdc++.h>
using namespace std;

int secondLargestElement(int arr[],int n) {
    int large = INT_MIN;
    int secondLarge = INT_MIN;
    for(int i = 0; i < n;i++) {
        if(arr[i] > large) {
            secondLarge = large;
            large = arr[i];
        }
        else if(arr[i] > secondLarge && arr[i] != large) {
            secondLarge = arr[i];
        }
    }
    return secondLarge;
}

int main() {
    int arr[] = {4,5,6,9,8,5,12,15};
    int n = 8;
    cout << "The Second largest element is " << secondLargestElement(arr,n) << endl;
    return 0;
}
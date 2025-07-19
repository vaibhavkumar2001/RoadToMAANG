#include<bits/stdc++.h>
using namespace std;

int findElement(int arr[],int n,int target) {
    for(int i = 0;i < n;i++) {
        if(arr[i] == target) {
            return i;
        }
    }
}
int main() {
    int arr[] = {2,4,4,8,9};
    int n = 5;
    int target = 4;
    cout << findElement(arr,n,target);
    return 0;
}
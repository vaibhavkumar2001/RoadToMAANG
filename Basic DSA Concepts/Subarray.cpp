#include<bits/stdc++.h>
using namespace std;
int findAllSubarrays(int arr[], int n) {
    for (int i = 0; i < n; i++) {           // start index
        for (int j = i; j < n; j++) {       // end index
            // print subarray from i to j
            for (int k = i; k <= j; k++) {
                cout << arr[k] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = 5;
    findAllSubarrays(arr, n);
    return 0;
}
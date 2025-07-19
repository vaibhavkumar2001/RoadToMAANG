// #include <iostream>
// #include <vector>
// using namespace std;

// Function to merge two sorted arrays
// vector<int> mergeSortedArrays(const vector<int>& arr1, const vector<int>& arr2) {
//     vector<int> merged;
//     int i = 0, j = 0;

 // Traverse both arrays and add smaller element to merged
//     while (i < arr1.size() && j < arr2.size()) {
//         if (arr1[i] < arr2[j]) {
//             merged.push_back(arr1[i]);
//             i++;
//         } else {
//             merged.push_back(arr2[j]);
//             j++;
//         }
//     }

  // Add remaining elements from arr1 (if any)
//     while (i < arr1.size()) {
//         merged.push_back(arr1[i]);
//         i++;
//     }

//     // Add remaining elements from arr2 (if any)
//     while (j < arr2.size()) {
//         merged.push_back(arr2[j]);
//         j++;
//     }

//     return merged;
// }

// int main() {
//     vector<int> arr1 = {1, 3, 5, 7};
//     vector<int> arr2 = {2, 4, 6, 8, 10};

//     vector<int> merged = mergeSortedArrays(arr1, arr2);

//     cout << "Merged Array: ";
//     for (int num : merged) {
//         cout << num << " ";
//     }
//     cout << endl;

//     return 0;
// }


// void reverseArray(int arr[],int n) {
//     int i = 0;
//     int j = n - 1;
//     while(i < j) {
//         swap(arr[i],arr[j]);
//         i++;
//         j--;
//     }
// }

// // 1 2 3

// sorted arry and target int is given we have to figure out all the subarrays 

// 2 4 4 8 9  target = 8




// 1 2 3 - this is called nested loops

// write a program to print the sum of every subarray of given ARRAY
// #include<bits/stdc++.h>
// using namespace std;
// int findSumArray(int arr[],int n,int target) {
//     int count = 0;
//     //after this nested loops will be getting all the subarrays
//     for(int i = 0;i < n;i++) {
//         for(int j = i;j < n;j++) {
//             int sum = 0;
//             for(int k = i;k <= j;k++) {
//                 sum += arr[k];
//             }
//             if(sum == target) {
//                 count++;
//             }
//         }
//     }
//     return count;
// }
// void findSumArray(int arr[],int n) {
//     //after this nested loops we will be getting all the subarrays
//     for(int i = 0;i < n;i++) {
//         for(int j = i;j < n;j++) {
//             // int sum = 0;
//             // for(int k = i;k <= j;k++) {
//             //     sum += arr[k];
//             // }
//             // if(sum == target) {
//             //     count++;
//             // }
//             // int startingIndex = i;
//             // int endingIndex = j;
//             cout << "The starting index is" << i << "The ending index is " << j << endl;
//         }
//     }
// }

// int main() {
//     int arr[] = {2,4,4,8,9};
//     int n = sizeof(arr)/sizeof(arr[0]);
//     int target = 8;
//     cout << findSumArray(arr,n,target) << endl;
//     return 0;
// }
// QUESTIONS ->

// given an array find all the subarrays whose starting element and ending element is equal to target
#include<bits/stdc++.h>
using namespace std;
void findTheTarget(int arr[],int n,int target) {
    for(int i = 0;i < n;i++) {
        for(int j = i;j < n;j++) {
            if(arr[i] == target && arr[j] == target) {
                cout << "The starting index is " << i << "The ending index is " << j << endl;
            }
        }
    }
}
int main() {
    int arr[] = {2,4,4,8,9};
    int n = 5;
    int target = 4;
    findTheTarget(arr,n,target);
    return 0;
}

//

// find count of subarrays,

// whose first element and last element are same

//print all the subarrays of size 3

// find starting and ending index of every single subarray

// What is the difference between subarray and subsequence     
//searching an item in an array 

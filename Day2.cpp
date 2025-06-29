#include <iostream>
#include <vector>
using namespace std;

// Function to merge two sorted arrays
vector<int> mergeSortedArrays(const vector<int>& arr1, const vector<int>& arr2) {
    vector<int> merged;
    int i = 0, j = 0;

    // Traverse both arrays and add smaller element to merged
    while (i < arr1.size() && j < arr2.size()) {
        if (arr1[i] < arr2[j]) {
            merged.push_back(arr1[i]);
            i++;
        } else {
            merged.push_back(arr2[j]);
            j++;
        }
    }

    // Add remaining elements from arr1 (if any)
    while (i < arr1.size()) {
        merged.push_back(arr1[i]);
        i++;
    }

    // Add remaining elements from arr2 (if any)
    while (j < arr2.size()) {
        merged.push_back(arr2[j]);
        j++;
    }

    return merged;
}

int main() {
    vector<int> arr1 = {1, 3, 5, 7};
    vector<int> arr2 = {2, 4, 6, 8, 10};

    vector<int> merged = mergeSortedArrays(arr1, arr2);

    cout << "Merged Array: ";
    for (int num : merged) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}


void reverseArray(int arr[],int n) {
    int i = 0;
    int j = n - 1;
    while(i < j) {
        swap(arr[i],arr[j]);
        i++;
        j--;
    }
}

// 1 2 3
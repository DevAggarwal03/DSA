#include "../stdc++.h"
using namespace std;

int partitionn(vector<int>& arr, int start, int end) {
    int pivot = arr[start];
    int count = 0;

    // Count how many elements are smaller than or equal to pivot
    for (int i = start + 1; i <= end; i++) {
        if (arr[i] <= pivot) {
            count++;
        }
    }

    // Place pivot at correct position
    int pivotActualIndex = start + count;
    swap(arr[pivotActualIndex], arr[start]);

    int i = start;
    int j = end;

    // Sort elements around pivot
    while (i < pivotActualIndex && j > pivotActualIndex) {
        while (arr[i] <= arr[pivotActualIndex]) {
            i++;
        }
        while (arr[j] > arr[pivotActualIndex]) {
            j--;
        }
        if (i < pivotActualIndex && j > pivotActualIndex) {
            swap(arr[i++], arr[j--]);
        }
    }

    return pivotActualIndex;
}

void quickSortt(vector<int>& arr, int start, int end) {
    if (start >= end) {
        return;
    }

    int p = partitionn(arr, start, end);

    // Recursively sort left and right subarrays
    quickSortt(arr, start, p - 1);
    quickSortt(arr, p + 1, end);
}

int main() {
    int n;
    cin >> n;

    vector<int> arr;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        arr.push_back(x);
    }

    quickSortt(arr, 0, n - 1);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}

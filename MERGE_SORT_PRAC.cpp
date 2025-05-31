#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

void merge(vector<int>& arr, int left, int mid, int right, vector<int>& temp) {
    int i = left;
    int j = mid + 1;
    int k = left;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }

    while (i <= mid) {
        temp[k++] = arr[i++];
    }

    while (j <= right) {
        temp[k++] = arr[j++];
    }

    for (int idx = left; idx <= right; ++idx) {
        arr[idx] = temp[idx];
    }
}

void mergeSortRecursive(vector<int>& arr, int left, int right, vector<int>& temp) {
    if (left >= right) return;

    int mid = left + (right - left) / 2;

    mergeSortRecursive(arr, left, mid, temp);
    mergeSortRecursive(arr, mid + 1, right, temp);
    merge(arr, left, mid, right, temp);
}

void mergeSort(vector<int>& arr) {
    if (arr.empty()) return;
    vector<int> temp(arr.size());
    mergeSortRecursive(arr, 0, static_cast<int>(arr.size()) - 1, temp);
}

void printVector(const vector<int>& v) {
    for (size_t i = 0; i < v.size(); ++i) {
        cout << v[i];
        if (i + 1 < v.size()) cout << " ";
    }
    cout << "\n";
}

void shuffleVector(vector<int>& v) {
    for (size_t i = 0; i + 1 < v.size(); ++i) {
        size_t j = i + (std::rand() % (v.size() - i));
        std::swap(v[i], v[j]);
    }
}

int main() {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    vector<int> arr1(10);
    for (int i = 0; i < 10; ++i) {
        arr1[i] = std::rand() % 100;
    }

    cout << "=== Test Case 1: Random Array ===\n";
    cout << "Before sorting: ";
    printVector(arr1);
    mergeSort(arr1);
    cout << "After sorting:  ";
    printVector(arr1);
    cout << "\n";

    vector<int> arr2 = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    cout << "=== Test Case 2: Already Sorted Array ===\n";
    cout << "Before sorting: ";
    printVector(arr2);
    mergeSort(arr2);
    cout << "After sorting:  ";
    printVector(arr2);
    cout << "\n";

    vector<int> arr3 = { 20, 18, 16, 14, 12, 10, 8, 6, 4, 2 };
    cout << "=== Test Case 3: Reverse Sorted Array ===\n";
    cout << "Before sorting: ";
    printVector(arr3);
    mergeSort(arr3);
    cout << "After sorting:  ";
    printVector(arr3);
    cout << "\n";

    vector<int> arr4 = { 5, 3, 8, 3, 9, 1, 5, 3, 7, 1 };
    cout << "=== Test Case 4: Array with Duplicates ===\n";
    cout << "Before sorting: ";
    printVector(arr4);
    mergeSort(arr4);
    cout << "After sorting:  ";
    printVector(arr4);
    cout << "\n";

    vector<int> arr5;
    cout << "=== Test Case 5: Empty Array ===\n";
    cout << "Before sorting: ";
    printVector(arr5);
    mergeSort(arr5);
    cout << "After sorting:  ";
    printVector(arr5);
    cout << "\n";

    return 0;
}

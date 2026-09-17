#include <iostream>
using namespace std;

// Bubble Sort
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Linear Search
int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            return i;
        }
    }
    return -1;
}

// Binary Search
int binarySearch(int arr[], int n, int key) {
    int low = 0;
    int high = n - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == key) {
            return mid;
        }
        else if (arr[mid] < key) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    return -1;
}

int main() {
    int n;

    cout << "Enter array size: ";
    cin >> n;

    int arr[n];

    cout << "Enter " << n << " elements:" << endl;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Sorting
    bubbleSort(arr, n);

    cout << "\nSorted array: ";

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    // Searching
    int key;
    cout << "\n\nEnter element to search: ";
    cin >> key;

    int linearResult = linearSearch(arr, n, key);

    if (linearResult != -1)
        cout << "Linear Search: Element found at position "
             << linearResult + 1 << endl;
    else
        cout << "Linear Search: Element not found" << endl;

    int binaryResult = binarySearch(arr, n, key);

    if (binaryResult != -1)
        cout << "Binary Search: Element found at position "
             << binaryResult + 1 << endl;
    else
        cout << "Binary Search: Element not found" << endl;

    cout << "\nTime Complexity:" << endl;
    cout << "Bubble Sort: O(n^2)" << endl;
    cout << "Linear Search: O(n)" << endl;
    cout << "Binary Search: O(log n)" << endl;

    return 0;
}
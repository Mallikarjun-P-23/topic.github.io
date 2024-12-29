#include <iostream>
using namespace std;

int binarySearch(int arr[], int size, int target) {
    int left = 0, right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) return mid;
        if (arr[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

int main() {
    int size, target;
    cout << "Enter the size of the array: ";
    cin >> size;
    int arr[size];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < size; i++) cin >> arr[i];
    cout << "Enter the target element: ";
    cin >> target;
    int result = binarySearch(arr, size, target);
    if (result != -1) cout << "Element found at index: " << result << endl;
    else cout << "Element not found!" << endl;
    return 0;
}

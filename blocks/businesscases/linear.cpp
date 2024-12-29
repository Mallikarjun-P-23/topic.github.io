#include <iostream>
using namespace std;

int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) return i;
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
    int result = linearSearch(arr, size, target);
    if (result != -1) cout << "Element found at index: " << result << endl;
    else cout << "Element not found!" << endl;
    return 0;
}

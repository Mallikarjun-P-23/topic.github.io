#include <iostream>
#include <vector>
using namespace std;


void heapBottomUp(vector<int>& H, int n) {
    for (int i = n / 2; i >= 1; --i) { 
        int k = i;
        int v = H[k];
        bool heap = false;

        while (!heap && 2 * k <= n) { 
            int j = 2 * k;            
            if (j < n && H[j] < H[j + 1]) { 
                j = j + 1;            
            }
            if (v >= H[j]) {          
                heap = true;
            } else {
                H[k] = H[j];          
                k = j;                
            }
        }
        H[k] = v;                     
    }
}


void heapSort(vector<int>& H, int n) {
    heapBottomUp(H, n);
    for (int i = n; i >= 2; --i) {
        swap(H[1], H[i]);
        n--;
        heapBottomUp(H, n);
    }
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> array(n + 1); 
    array[0] = 0; 
    cout << "Enter the elements of the array: ";
    for (int i = 1; i <= n; ++i) {
        cin >> array[i];
    }

    cout << "Original Array: ";
    for (int i = 1; i <= n; ++i) cout << array[i] << " ";
    cout << endl;

    heapSort(array, n);

    cout << "Sorted Array: ";
    for (int i = 1; i <= n; ++i) cout << array[i] << " ";
    cout << endl;

    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>

class QuickSort {
private:
    std::vector<int> arr;

    int partition(int l, int r) {
        int p = arr[l];
        int i = l;
        int j = r + 1;

        while (true) {
            do {
                i++;
            } while (i <= r && arr[i] < p);

            do {
                j--;
            } while (arr[j] > p);

            if (i >= j) break;

            std::swap(arr[i], arr[j]);
        }

        std::swap(arr[l], arr[j]);

        return j;
    }

    void quickSort(int l, int r) {
        if (l < r) {
            int s = partition(l, r);
            quickSort(l, s - 1);
            quickSort(s + 1, r);
        }
    }

public:
    QuickSort(std::vector<int>& inputArr) {
        arr = inputArr;
    }

    void sort() {
        quickSort(0, arr.size() - 1);
    }

    void printArray() const {
        for (int num : arr) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    int n;
    std::cout << "Enter the size of the array: ";
    std::cin >> n;

    std::vector<int> array(n);
    std::cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        std::cin >> array[i];
    }

    QuickSort qs(array);

    std::cout << "Before sorting: ";
    qs.printArray();

    qs.sort();

    std::cout << "After sorting: ";
    qs.printArray();

    return 0;
}

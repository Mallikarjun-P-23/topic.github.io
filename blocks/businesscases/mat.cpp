#include <bits/stdc++.h>
using namespace std;

struct Allocation {
    string process_name;
    char* start_address;
    int size;
    char* end_address;
};

struct FreeBlock {
    char* start_address;
    int size;
    char* end_address;
};

void allocate(char* myheap, vector<Allocation>& mat, int size, const string& process_name) {
    int total_used = 0;
    for (const auto& alloc : mat) {
        total_used += alloc.size;
    }

    if (total_used + size > 500 * 1024 * 1024) {
        cout << "Not enough memory available to allocate " << size << " bytes.\n";
        return;
    }

    if (mat.empty() || (mat[0].start_address - myheap) >= size) {
        mat.push_back({process_name, myheap, size, myheap + size - 1});
        cout << "Allocated " << size << " bytes for process " << process_name << " from " << (void*)myheap << " to " << (void*)(myheap + size - 1) << "\n";
        return;
    }

    for (int i = 1; i < mat.size(); i++) {
        if ((mat[i].start_address - mat[i - 1].end_address) >= size) {
            char* start_address = mat[i - 1].end_address + 1;
            mat.push_back({process_name, start_address, size, start_address + size - 1});
            cout << "Allocated " << size << " bytes for process " << process_name << " from " << (void*)start_address << " to " << (void*)(start_address + size - 1) << "\n";
            return;
        }
    }

    char* start_address = myheap + total_used;
    char* end_address = start_address + size - 1;
    mat.push_back({process_name, start_address, size, end_address});
    cout << "Allocated " << size << " bytes for process " << process_name << " from " << (void*)start_address << " to " << (void*)end_address << "\n";
}

void display(const vector<Allocation>& mat) {
    for (const auto& alloc : mat) {
        cout << "\nProcess: " << alloc.process_name << " Start Address: " << (void*)alloc.start_address
             << " Size: " << alloc.size << " bytes End Address: " << (void*)alloc.end_address << endl;
    }
}

void mysort(vector<Allocation>& mat) {
    sort(mat.begin(), mat.end(), [](const Allocation& a, const Allocation& b) {
        return a.start_address < b.start_address;
    });
}

void sort_size_display(vector<Allocation>& mat) {
    sort(mat.begin(), mat.end(), [](const Allocation& a, const Allocation& b) {
        return a.size < b.size;
    });
    display(mat);
}

void deallocate(vector<Allocation>& mat) {
    string pr;
    cout << "Enter the process you want to delete: ";
    cin >> pr;

    for (auto it = mat.begin(); it != mat.end(); ++it) {
        if (it->process_name == pr) {
            mat.erase(it);
            cout << "Process " << pr << " deallocated.\n";
            return;
        }
    }
    cout << "Process " << pr << " not found.\n";
}

void helper(vector<FreeBlock>& freesize, const vector<Allocation>& mat, char* myheap) {
    freesize.clear();
    int n = mat.size();
    if (mat.empty()) {
        freesize.push_back({myheap, 500 * 1024 * 1024, myheap + 500 * 1024 * 1024 - 1});
    } else {
        if (mat[0].start_address - myheap > 0) {
            freesize.push_back({myheap, mat[0].start_address - myheap, mat[0].start_address - 1});
        }
        for (int i = 1; i < n; i++) {
            if (mat[i].start_address - mat[i - 1].end_address > 0) {
                freesize.push_back({mat[i - 1].end_address + 1, mat[i].start_address - mat[i - 1].end_address - 1, mat[i].start_address - 1});
            }
        }
        if (myheap + 500 * 1024 * 1024 - mat.back().end_address > 0) {
            freesize.push_back({mat.back().end_address + 1, myheap + 500 * 1024 * 1024 - mat.back().end_address, myheap + 500 * 1024 * 1024 - 1});
        }
    }

    for (const auto& block : freesize) {
        cout << "\nStart address: " << (void*)block.start_address << " Size in bytes: " << block.size << " End address: " << (void*)block.end_address;
    }
    cout << endl;
}

int main() {
    vector<Allocation> mat;
    vector<FreeBlock> freesize;

    char* myheap = (char*)malloc(500 * 1024 * 1024);
    cout << "myheap is initialized to 500 MB of data storage space" << endl;

    int ch, size;
    string process_name;
    while (true) {
        cout << "\nEnter the choice:\n1. Allocate memory\n2. Display allocations\n3. Deallocate memory\n4. Exit\n5. Sort by size and display\n6. Free space table\nChoice: ";
        cin >> ch;

        mysort(mat);

        switch (ch) {
            case 1:
                cout << "Enter process name: ";
                cin >> process_name;
                cout << "Enter size to be allocated for the process (in MB): ";
                cin >> size;
                size *= 1024 * 1024;

                if (size > 50 * 1024 * 1024) {
                    cout << "Memory should be less than 50 MB\n";
                } else {
                    allocate(myheap, mat, size, process_name);
                }
                break;
            case 2:
                display(mat);
                break;
            case 3:
                deallocate(mat);
                break;
            case 4:
                free(myheap);
                return 0;
            case 5:
                sort_size_display(mat);
                break;
            case 6:
                helper(freesize, mat, myheap);
                break;
            default:
                cout << "Invalid choice, try again.\n";
                break;
        }
    }
}

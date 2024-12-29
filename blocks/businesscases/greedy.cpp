#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Department {
    string name;
    int demand; // resources needed by the department
};

bool compare(Department a, Department b) {
    return a.demand > b.demand; // Sort departments by demand in descending order
}

void allocateResources(int totalResources, vector<Department>& departments) {
    // Sort departments based on demand in descending order
    sort(departments.begin(), departments.end(), compare);
    
    cout << "Resource Allocation:\n";
    for (auto& dept : departments) {
        if (totalResources >= dept.demand) {
            // Allocate resources to this department
            cout << "Allocating " << dept.demand << " resources to " << dept.name << endl;
            totalResources -= dept.demand; // Decrease the available resources
        } else {
            // If not enough resources, allocate what's left
            cout << "Allocating " << totalResources << " resources to " << dept.name << endl;
            totalResources = 0; // All resources are allocated
        }
    }

    if (totalResources > 0) {
        cout << "Remaining resources: " << totalResources << endl;
    } else {
        cout << "No remaining resources." << endl;
    }
}

int main() {
    int totalResources, numDepartments;

    // Take user input for total resources and number of departments
    cout << "Enter the total resources available: ";
    cin >> totalResources;
    
    cout << "Enter the number of departments: ";
    cin >> numDepartments;

    vector<Department> departments(numDepartments);

    // Take user input for department names and their resource demands
    for (int i = 0; i < numDepartments; i++) {
        cout << "Enter the name of department " << i + 1 << ": ";
        cin >> departments[i].name;
        cout << "Enter the resource demand for " << departments[i].name << ": ";
        cin >> departments[i].demand;
    }

    // Allocate resources
    allocateResources(totalResources, departments);

    return 0;
}
problem 4

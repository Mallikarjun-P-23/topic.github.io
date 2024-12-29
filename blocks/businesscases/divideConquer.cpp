#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

// Customer class to store customer information
class Customer {
public:
    string name;
    int age;
    string gender;
    vector<string> pastPurchases;

    Customer(string n, int a, string g, vector<string> p)
        : name(n), age(a), gender(g), pastPurchases(p) {}
};

// Function to filter customers by past product purchases
vector<Customer> filterByProduct(vector<Customer>& customers, const string& targetProduct) {
    vector<Customer> targetCustomers;

    for (auto& customer : customers) {
        // Check if the customer has purchased the target product
        for (const auto& purchase : customer.pastPurchases) {
            if (purchase == targetProduct) {
                targetCustomers.push_back(customer);
                break; // Stop checking once the product is found
            }
        }
    }

    return targetCustomers;
}

// Main function to test the solution
int main() {
    vector<Customer> customers;

    // Input number of customers
    int n;
    cout << "Enter the number of customers: ";
    cin >> n;

    // Collect customer data
    for (int i = 0; i < n; ++i) {
        string name, gender;
        int age, numPurchases;
        cout << "Enter customer " << i + 1 << " details:\n";
        cout << "Name: ";
        cin >> name;
        cout << "Age: ";
        cin >> age;
        cout << "Gender: ";
        cin >> gender;
        cout << "Enter number of past purchases: ";
        cin >> numPurchases;

        vector<string> pastPurchases(numPurchases);
        cout << "Enter past purchases (separated by spaces): ";
        for (int j = 0; j < numPurchases; ++j) {
            cin >> pastPurchases[j];
        }

        customers.push_back(Customer(name, age, gender, pastPurchases));
    }

    // Input the target product to filter customers
    string targetProduct;
    cout << "Enter the product to filter customers: ";
    cin >> targetProduct;

    // Get customers who have purchased the target product
    vector<Customer> productCustomers = filterByProduct(customers, targetProduct);

    // Output customers who have purchased the target product
    if (productCustomers.empty()) {
        cout << "No customers have purchased " << targetProduct << ".\n";
    } else {
        cout << "\nCustomers who have purchased " << targetProduct << ":\n";
        for (const auto& customer : productCustomers) {
            cout << customer.name << ", Age: " << customer.age << ", Gender: " << customer.gender << endl;
        }
    }

    return 0;
}

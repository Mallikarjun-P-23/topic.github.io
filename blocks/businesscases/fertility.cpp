#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

// Structure to store information for each plot
struct Plot {
    int id;
    float pH;
    float nitrogen;
    float phosphorus;
    float potassium;
    float fertilityScore;

    // Function to calculate the fertility score based on pH and NPK values
    void calculateFertility() {
        // Fertility score formula (simplified example)
        // Assume ideal pH range is 6.5 to 7.5 (adjust according to your requirements)
        float pHScore = (pH >= 6.5 && pH <= 7.5) ? 1.0 : 0.5;
        float npkScore = (nitrogen + phosphorus + potassium) / 3.0;

        fertilityScore = pHScore * npkScore; // A simple combination of pH and NPK for fertility score
    }
};

// Function to compare two plots based on fertility score
bool compareByFertility(const Plot &a, const Plot &b) {
    return a.fertilityScore > b.fertilityScore; // Higher score is better
}

int main() {
    int n;

    // Input number of plots
    cout << "Enter the number of plots: ";
    cin >> n;

    vector<Plot> plots(n);

    // Input data for each plot
    for (int i = 0; i < n; ++i) {
        plots[i].id = i + 1; // Assign unique ID to each plot
        cout << "Enter data for Plot " << plots[i].id << " (pH, Nitrogen, Phosphorus, Potassium): ";
        cin >> plots[i].pH >> plots[i].nitrogen >> plots[i].phosphorus >> plots[i].potassium;
        plots[i].calculateFertility(); // Calculate fertility score
    }

    // Sort plots based on fertility score
    sort(plots.begin(), plots.end(), compareByFertility);

    // Display sorted plot numbers and fertility scores
    cout << fixed << setprecision(2);
    cout << "\nSorted plots by fertility score:\n";

    for (const auto &plot : plots) {
        cout << "Plot " << plot.id << " | Fertility Score: " << plot.fertilityScore << endl;
    }

    return 0;
}

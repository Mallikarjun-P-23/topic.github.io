#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to store the details of each plot
struct Plot {
    int plot_number;
    float water_needed;   // Water needed after considering soil moisture
    float soil_moisture;  // Soil moisture percentage (0 to 100)
    float water_to_supply; // Actual water that will be supplied
};

// Comparator function to sort by water_needed in descending order
bool compare_by_water_needed(const Plot& a, const Plot& b) {
    return a.water_needed > b.water_needed;
}

// Function to calculate water needed for each plot
void calculateWater(Plot &plot) {
    // Simulated water requirement calculation based on soil moisture
    // Let's assume base water needed is 100 (you can modify this based on crop types)
    float base_water = 100;
    plot.water_needed = base_water * (1 - plot.soil_moisture / 100);
}

// Function to distribute water proportionally based on water_needed
float distributeWater(vector<Plot>& plots, float total_water) {
    // Calculate the total required water for all plots
    float total_required_water = 0;
    for (const auto& plot : plots) {
        total_required_water += plot.water_needed;
    }

    // If the total required water is more than the available water, distribute proportionally
    if (total_required_water > total_water) {
        // Distribute water proportionally
        for (auto& plot : plots) {
            plot.water_to_supply = (plot.water_needed / total_required_water) * total_water;
        }
        return 0; // No unused water
    } else {
        // If total required water is less than available, give full water supply to each plot
        for (auto& plot : plots) {
            plot.water_to_supply = plot.water_needed;
        }
        return total_water - total_required_water; // Remaining water
    }
}

int main() {
    int n;
    cout << "Enter the number of plots: ";
    cin >> n;

    vector<Plot> plots(n);

    // Input the plot details
    for (int i = 0; i < n; i++) {
        cout << "Enter details for plot " << i + 1 << ":\n";
        plots[i].plot_number = i + 1;
        cout << "Soil moisture for plot " << i + 1 << " (0 to 100): ";
        cin >> plots[i].soil_moisture;

        // Calculate the water needed based on soil moisture
        calculateWater(plots[i]);
    }

    float total_water;
    cout << "Enter the total available water for irrigation: ";
    cin >> total_water;

    // Sort the plots based on water needed in descending order
    sort(plots.begin(), plots.end(), compare_by_water_needed);

    // Distribute the water
    float unused_water = distributeWater(plots, total_water);

    // Output the result
    cout << "\nWater distribution for each plot:\n";
    for (const auto& plot : plots) {
        cout << "Plot " << plot.plot_number << " will receive " << plot.water_to_supply << " units of water.\n";
    }

    cout << "\nUnused water: " << unused_water << " units." << endl;

    return 0;
}
irrigation

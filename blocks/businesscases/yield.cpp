#include <iostream>
#include <vector>
using namespace std;

double predictYield(const vector<double>& x, const vector<double>& y, double input) {
    double n = x.size();
    double sumX = 0, sumY = 0, sumXY = 0, sumX2 = 0;

    for (int i = 0; i < n; ++i) {
        sumX += x[i];
        sumY += y[i];
        sumXY += x[i] * y[i];
        sumX2 += x[i] * x[i];
    }

    double slope = (n * sumXY - sumX * sumY) / (n * sumX2 - sumX * sumX);
    double intercept = (sumY - slope * sumX) / n;

    return slope * input + intercept;
}

int main() {
    int n;
    cout << "Enter the number of data points: ";
    cin >> n;

    vector<double> rainfall(n), yield(n);

    cout << "Enter the rainfall values: \n";
    for (int i = 0; i < n; ++i) {
        cin >> rainfall[i];
    }

    cout << "Enter the corresponding yield values: \n";
    for (int i = 0; i < n; ++i) {
        cin >> yield[i];
    }

    double inputRainfall;
    cout << "Enter the rainfall value to predict yield: ";
    cin >> inputRainfall;

    cout << "Predicted Yield: " << predictYield(rainfall, yield, inputRainfall) << endl;
    return 0;
}

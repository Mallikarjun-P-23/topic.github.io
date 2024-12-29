#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

// Function to simulate the demand based on price
// The higher the price, the lower the demand (a simple linear model)
int calculateDemand(int price) {
    // Example: Demand decreases as price increases
    return max(0, 100 - price);  // Simple demand curve: max(0, 100 - price)
}

// Function to find the optimal price using a greedy strategy
int greedyPricingStrategy(int initialPrice, int minPrice, int maxPrice, const vector<int>& competitorPrices) {
    int bestPrice = initialPrice;
    int bestRevenue = calculateDemand(initialPrice) * initialPrice;

    // Try all prices within the range [minPrice, maxPrice]
    for (int price = minPrice; price <= maxPrice; ++price) {
        // Check competitor prices and adjust based on that (we assume a simple rule: not too far from competitors)
        int avgCompetitorPrice = 0;
        for (int competitorPrice : competitorPrices) {
            avgCompetitorPrice += competitorPrice;
        }
        avgCompetitorPrice /= competitorPrices.size();

        // We want to be competitive, so adjust the price towards the average of competitors
        int adjustedPrice = price + (avgCompetitorPrice - price) / 2;

        // Calculate demand based on the adjusted price
        int demand = calculateDemand(adjustedPrice);

        // Calculate revenue (price * demand)
        int revenue = adjustedPrice * demand;

        // If this revenue is better than the previous best, update the best price
        if (revenue > bestRevenue) {
            bestRevenue = revenue;
            bestPrice = adjustedPrice;
        }
    }

    return bestPrice;
}

int main() {
    int initialPrice, minPrice, maxPrice, numCompetitors;

    // Take user input for initial price and price range
    cout << "Enter the initial price of the product: ";
    cin >> initialPrice;

    cout << "Enter the minimum price: ";
    cin >> minPrice;

    cout << "Enter the maximum price: ";
    cin >> maxPrice;

    cout << "Enter the number of competitors: ";
    cin >> numCompetitors;

    vector<int> competitorPrices(numCompetitors);

    // Take user input for competitor prices
    cout << "Enter the competitor prices:\n";
    for (int i = 0; i < numCompetitors; ++i) {
        cin >> competitorPrices[i];
    }

    // Find the optimal price using the greedy pricing strategy
    int optimalPrice = greedyPricingStrategy(initialPrice, minPrice, maxPrice, competitorPrices);

    cout << "The optimal price for the product is: " << optimalPrice << endl;

    return 0;
}

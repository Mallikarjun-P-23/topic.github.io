#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
using namespace std;

// Marketing Campaign class to store information about each campaign
class Campaign {
public:
    string channel;
    int performanceScore; // Performance score for this campaign

    Campaign(string ch, int score) : channel(ch), performanceScore(score) {}
};

// Function to evaluate the total performance of a combination of channels
int evaluatePerformance(const vector<Campaign>& campaigns, const vector<bool>& selectedChannels) {
    int totalPerformance = 0;
    for (size_t i = 0; i < selectedChannels.size(); ++i) {
        if (selectedChannels[i]) {
            totalPerformance += campaigns[i].performanceScore;
        }
    }
    return totalPerformance;
}

// Backtracking function to explore combinations of marketing channels
void backtrack(const vector<Campaign>& campaigns, vector<bool>& selectedChannels, int idx, int& bestScore, vector<bool>& bestCombination) {
    if (idx == campaigns.size()) {
        // Evaluate the current combination of selected channels
        int currentScore = evaluatePerformance(campaigns, selectedChannels);
        
        // Update the best combination if the current one is better
        if (currentScore > bestScore) {
            bestScore = currentScore;
            bestCombination = selectedChannels;
        }
        return;
    }

    // Case 1: Do not select this channel
    selectedChannels[idx] = false;
    backtrack(campaigns, selectedChannels, idx + 1, bestScore, bestCombination);

    // Case 2: Select this channel
    selectedChannels[idx] = true;
    backtrack(campaigns, selectedChannels, idx + 1, bestScore, bestCombination);
}

// Main function to take user input and run the backtracking algorithm
int main() {
    int n;
    cout << "Enter the number of marketing channels: ";
    cin >> n;

    vector<Campaign> campaigns;
    
    // Input campaign data
    for (int i = 0; i < n; ++i) {
        string channel;
        int performanceScore;
        
        cout << "Enter channel name: ";
        cin >> channel;
        cout << "Enter performance score for " << channel << ": ";
        cin >> performanceScore;
        
        campaigns.push_back(Campaign(channel, performanceScore));
    }

    vector<bool> selectedChannels(n, false); // Keeps track of selected channels
    vector<bool> bestCombination(n, false); // Best combination of channels
    int bestScore = INT_MIN; // Initialize to a very low value
    
    // Call the backtracking function to find the best combination
    backtrack(campaigns, selectedChannels, 0, bestScore, bestCombination);

    // Output the best combination of marketing channels
    cout << "\nBest Combination of Channels: " << endl;
    cout << "Total Performance Score: " << bestScore << endl;
    for (int i = 0; i < n; ++i) {
        if (bestCombination[i]) {
            cout << campaigns[i].channel << endl;
        }
    }

    return 0;
}

#include <iostream>
using namespace std;

int bruteForceSearch(string text, string pattern) {
    int n = text.length();
    int m = pattern.length();
    for (int i = 0; i <= n - m; i++) {
        int j = 0;
        while (j < m && text[i + j] == pattern[j]) {
            j++;
        }
        if (j == m) return i;
    }
    return -1;
}

int main() {
    string text, pattern;
    cout << "Enter the text: ";
    cin >> text;
    cout << "Enter the pattern: ";
    cin >> pattern;
    
    int result = bruteForceSearch(text, pattern);
    if (result != -1) cout << "Pattern found at index: " << result << endl;
    else cout << "Pattern not found!" << endl;
    return 0;
}

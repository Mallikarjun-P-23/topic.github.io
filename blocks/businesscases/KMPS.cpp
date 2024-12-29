#include <iostream>
#include <vector>
using namespace std;

void computeLPSArray(string pat, vector<int>& lps) {
    int length = 0;
    int i = 1;
    while (i < pat.length()) {
        if (pat[i] == pat[length]) {
            length++;
            lps[i] = length;
            i++;
        } else {
            if (length != 0) {
                length = lps[length - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

int KMPSearch(string text, string pat) {
    vector<int> lps(pat.length(), 0);
    computeLPSArray(pat, lps);
    int i = 0, j = 0;
    while (i < text.length()) {
        if (pat[j] == text[i]) {
            i++;
            j++;
        }
        if (j == pat.length()) {
            return i - j;
            j = lps[j - 1];
        } else if (i < text.length() && pat[j] != text[i]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }
    return -1;
}

int main() {
    string text, pat;
    cout << "Enter the text: ";
    cin >> text;
    cout << "Enter the pattern: ";
    cin >> pat;
    int result = KMPSearch(text, pat);
    if (result != -1) cout << "Pattern found at index: " << result << endl;
    else cout << "Pattern not found!" << endl;
    return 0;
}

#include <iostream>
#include <vector>
using namespace std;

void warshall(vector<vector<int>> &A) {
    int n = A.size();
    vector<vector<int>> R = A;

    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                R[i][j] = R[i][j] || (R[i][k] && R[k][j]);
            }
        }
    }

    cout << "Transitive closure of the graph:" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << R[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> A(n, vector<int>(n));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> A[i][j];
        }
    }

    warshall(A);

    return 0;
}
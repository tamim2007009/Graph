#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    // Initialize n+1 by n+1 matrix with zeros
    vector<vector<int>> mat(n + 1, vector<int>(n + 1, 0));

    // Read edges
    for (int i = 0; i < m; ++i) {
        int u, v, wt;
        cin >> u >> v >> wt;
        mat[u][v] = wt;
        mat[v][u] = wt;  // because undirected
    }

    // Print header row
    cout << "    ";
    for (int j = 1; j <= n; ++j)
        cout << setw(4) << j;
    cout << "\n";

    // Print matrix rows
    for (int i = 1; i <= n; ++i) {
        cout << setw(4) << i;
        for (int j = 1; j <= n; ++j) {
            cout << setw(4) << mat[i][j];
        }
        cout << "\n";
    }

    return 0;
}
// 5 6
// 1 2 3
// 1 3 5
// 2 4 4
// 3 4 2
// 4 5 1
// 2 5 7
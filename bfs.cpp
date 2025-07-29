#include <bits/stdc++.h>
using namespace std;

void bfs(const vector<vector<int>>& adj, int start) {
    int N = (int)adj.size() - 1;       // actual number of nodes
    vector<int> vis(N + 1, 0), order;
    queue<int> q;

    vis[start] = 1;
    q.push(start);

    while (!q.empty()) {
        int u = q.front(); q.pop();
        order.push_back(u);

        for (int v : adj[u]) {
            if (!vis[v]) {
                vis[v] = 1;
                q.push(v);
            }
        }
    }

    for (int x : order)
        cout << x << ' ';
    cout << '\n';
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);
    for (int i = 0, u, v; i < m; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int start;
    cin >> start;
    bfs(adj, start);

    return 0;
}

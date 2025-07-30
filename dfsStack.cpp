#include <bits/stdc++.h>
using namespace std;

void dfs(const vector<vector<int>>& adj, int start) {
    int N = (int)adj.size() - 1;       // actual number of nodes
    vector<int> vis(N + 1, 0), order;
    stack<int> st;

    st.push(start);

    while (!st.empty()) {
        int u = st.top(); st.pop();

        if (vis[u]) continue;
        vis[u] = 1;
        order.push_back(u);

        for (auto it :adj[u]) {
            if (!vis[it]) {
                st.push(it);
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
    dfs(adj, start);

    return 0;
}

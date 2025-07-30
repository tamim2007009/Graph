#include <bits/stdc++.h>
using namespace std;
vector<int> order;

void dfs(vector<vector<int>> &adj, int node, vector<int> &vis) {

  vis[node] = 1;
  order.push_back(node);
  for (auto it : adj[node]) {
    if (!vis[it]) {
      dfs(adj, it, vis);
    }
  }
}
int main() {

  int n, m;
  cin >> n >> m;
  vector<int> vis(n + 1, 0);

  vector<vector<int>> adj(n + 1);

  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  int start;
  cin >> start;

  dfs(adj, start, vis);
  for (auto it : order) {
    cout << it << "->";
  }
  cout << endl;

  return 0;
}
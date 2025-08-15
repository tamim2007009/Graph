#include <iostream>
#include <queue>
#include <utility>
#include <vector>


using namespace std;

void aStarSearch(int start, int goal, vector<vector<pair<int, int>>> &adj,
                 vector<int> &heuristic) {
  int n = adj.size();
  vector<bool> visited(n, false);
  vector<int> g(n, 1e9); // cost from start to node
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>>
      pq; // {f = g + h, node}

  g[start] = 0;
  pq.push({heuristic[start], start});

  cout << "Path: ";

  while (!pq.empty()) {
    int current = pq.top().second;
    pq.pop();

    if (visited[current])
      continue;

    visited[current] = true;
    cout << current << " ";

    if (current == goal) {
      cout << "\nGoal reached!" << endl;
      return;
    }

    for (auto &neighbor : adj[current]) {
      int next = neighbor.first;
      int cost = neighbor.second;

      if (!visited[next]) {
        int new_g = g[current] + cost;
        if (new_g < g[next]) {
          g[next] = new_g;
          int f = new_g + heuristic[next];
          pq.push({f, next});
        }
      }
    }
  }

  cout << "\nGoal not reachable." << endl;
}

int main() {
  int n = 6;

  // Adjacency list: (neighbor, cost)
  vector<vector<pair<int, int>>> adj(n);
  adj[0] = {{1, 1}, {2, 1}};
  adj[1] = {{0, 1}, {3, 1}, {4, 1}};
  adj[2] = {{0, 1}, {5, 1}};
  adj[3] = {{1, 1}};
  adj[4] = {{1, 1}};
  adj[5] = {{2, 1}};

  // Heuristic values
  vector<int> heuristic = {7, 6, 2, 1, 0, 3};

  int start = 0;
  int goal = 4;

  aStarSearch(start, goal, adj, heuristic);

  return 0;
}

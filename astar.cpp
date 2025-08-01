#include<bits/stdc++.h>
using namespace std;

// A* Search without custom comparator
void aStarSearch(int start, int goal, vector<vector<pair<int, int>>>& adj, vector<int>& heuristic) {
    int n = adj.size();
    vector<int> g(n, INT_MAX);       // cost from start to node
    vector<int> f(n, INT_MAX);       // estimated total cost (f = g + h)
    vector<bool> visited(n, false);
    vector<int> parent(n, -1);

    g[start] = 0;
    f[start] = heuristic[start];

    vector<int> open = {start};  // open list

    while (!open.empty()) {
        // Find node with lowest f-cost
        int current = open[0];
        for (int node : open) {
            if (f[node] < f[current])
                current = node;
        }

        if (current == goal) {
            // Reconstruct path
            vector<int> path;
            while (current != -1) {
                path.push_back(current);
                current = parent[current];
            }
            cout << "Path: ";
            for (int i = path.size() - 1; i >= 0; --i)
                cout << path[i] << " ";
            cout << "\nTotal Cost: " << g[goal] << endl;
            return;
        }

        // Remove current from open list
        open.erase(remove(open.begin(), open.end(), current), open.end());
        visited[current] = true;

        for (auto& neighbor : adj[current]) {
            int next = neighbor.first;
            int cost = neighbor.second;

            if (visited[next]) continue;

            int tentative_g = g[current] + cost;

            if (tentative_g < g[next]) {
                g[next] = tentative_g;
                f[next] = g[next] + heuristic[next];
                parent[next] = current;

                // Add to open list if not already present
                if (find(open.begin(), open.end(), next) == open.end())
                    open.push_back(next);
            }
        }
    }

    cout << "Path not found.\n";
}

int main() {
    int n = 6;
    vector<vector<pair<int, int>>> adj(n);

    // Example edges: (u, v, cost)
    adj[0].push_back({1, 2});
    adj[0].push_back({2, 4});
    adj[1].push_back({2, 1});
    adj[1].push_back({3, 7});
    adj[2].push_back({4, 3});
    adj[4].push_back({3, 2});
    adj[3].push_back({5, 1});
    adj[4].push_back({5, 5});

    // Heuristic values (estimated cost to goal node 5)
    vector<int> heuristic = {10, 8, 5, 3, 1, 0};

    int start = 0;
    int goal = 5;

    aStarSearch(start, goal, adj, heuristic);

    return 0;
}

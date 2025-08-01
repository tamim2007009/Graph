#include <iostream>
#include <vector>
#include <set>

using namespace std;

void greedyBestFirstSearch(int start, int goal, vector<vector<int>>& adj, vector<int>& heuristic) {
    int n = adj.size();
    vector<bool> visited(n, false);
    set<pair<int, int>> s;  // {heuristic, node}

    s.insert({heuristic[start], start});
    visited[start] = true;

    cout << "Path: ";

    while (!s.empty()) {
        int current = s.begin()->second;
        s.erase(s.begin());

        cout << current << " ";

        if (current == goal) {
            cout << "\nGoal reached!" << endl;
            return;
        }

        for (int neighbor : adj[current]) {
            if (!visited[neighbor]) {
                s.insert({heuristic[neighbor], neighbor});
                visited[neighbor] = true;
            }
        }
    }

    cout << "\nGoal not reachable." << endl;
}

int main() {
    int n = 6; // number of nodes (0 to 5)

    // Adjacency list
    vector<vector<int>> adj(n);
    adj[0] = {1, 2};
    adj[1] = {0, 3, 4};
    adj[2] = {0, 5};
    adj[3] = {1};
    adj[4] = {1};
    adj[5] = {2};

    // Heuristic values for each node (example: estimated cost to reach goal)
    vector<int> heuristic = {7, 6, 2, 1, 0, 3};

    int start = 0;
    int goal = 4;

    greedyBestFirstSearch(start, goal, adj, heuristic);

    return 0;
}

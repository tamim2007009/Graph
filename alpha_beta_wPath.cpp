#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int value;
    string name;
    vector<Node> children;

    Node(string n, int val) : name(n), value(val) {}
    Node(string n, int val, vector<Node> childs) : name(n), value(val), children(childs) {}
};

// Function returns pair {bestValue, path of names}
pair<int, vector<string>> minimax(const Node& node, int depth, bool maximizingPlayer, int alpha, int beta) {
    if (depth == 0 || node.children.empty()) {
        return {node.value, {}};  // Leaf: return value, no name in path
    }

    if (maximizingPlayer) {
        int maxEval = INT_MIN;
        vector<string> bestPath;
        for (const auto& child : node.children) {
            pair<int, vector<string>> result = minimax(child, depth - 1, false, alpha, beta);
            int eval = result.first;
            vector<string> path = result.second;
            if (eval > maxEval) {
                maxEval = eval;
                bestPath = path;
                bestPath.insert(bestPath.begin(), child.name);
            }
            alpha = max(alpha, eval);
            if (beta <= alpha) break; // Beta cutoff
        }
        return {maxEval, bestPath};
    } else {
        int minEval = INT_MAX;
        vector<string> bestPath;
        for (const auto& child : node.children) {
            pair<int, vector<string>> result = minimax(child, depth - 1, true, alpha, beta);
            int eval = result.first;
            vector<string> path = result.second;
            if (eval < minEval) {
                minEval = eval;
                bestPath = path;
                bestPath.insert(bestPath.begin(), child.name);
            }
            beta = min(beta, eval);
            if (beta <= alpha) break; // Alpha cutoff
        }
        return {minEval, bestPath};
    }
}

int main() {
    // Leaves
    Node n1("n1", 3), n2("n2", 4), n3("n3", 2), n4("n4", 1),
         n5("n5", 7), n6("n6", 8), n7("n7", 9), n8("n8", 10),
         n9("n9", 2), n10("n10", 11), n11("n11", 1), n12("n12", 12),
         n13("n13", 14), n14("n14", 9), n15("n15", 13), n16("n16", 16);

    // Min nodes
    Node min1("min1", 0, {n1, n2});
    Node min2("min2", 0, {n3, n4});
    Node min3("min3", 0, {n5, n6});
    Node min4("min4", 0, {n7, n8});
    Node min5("min5", 0, {n9, n10});
    Node min6("min6", 0, {n11, n12});
    Node min7("min7", 0, {n13, n14});
    Node min8("min8", 0, {n15, n16});

    // Max nodes
    Node max1("max1", 0, {min1, min2});
    Node max2("max2", 0, {min3, min4});
    Node max3("max3", 0, {min5, min6});
    Node max4("max4", 0, {min7, min8});

    // Min nodes
    Node min9("min9", 0, {max1, max2});
    Node min10("min10", 0, {max3, max4});

    // Root (Max node)
    Node root("root", 0, {min9, min10});

    // Run minimax with alpha-beta
    pair<int, vector<string>> result = minimax(root, 4, true, INT_MIN, INT_MAX);
    int optimalValue = result.first;
    vector<string> path = result.second;

    cout << "Optimal value: " << optimalValue << endl;

    cout << "Path: root ";
    for (string n : path) cout << "-> " << n << " ";
    cout << endl;

    return 0;
}

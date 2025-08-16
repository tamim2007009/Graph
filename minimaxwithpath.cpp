#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int value;              
    string name;            
    vector<Node> children;  

    Node(string n, int val) { // Leaf node
        name = n;
        value = val;
    }

    Node(string n, int val, vector<Node> childs) { // Internal node
        name = n;
        value = val;
        children = childs;
    }
};

// Function returns {bestValue, path of names}
pair<int, vector<string>> minimaxPath(const Node& node, int depth, bool maximizingPlayer) {
    if (depth == 0 || node.children.empty()) {
        return {node.value, {}};  // leaf: return value, but no name
    }

    if (maximizingPlayer) {
        int maxEval = INT_MIN;
        vector<string> bestPath;
        for (const auto& child : node.children) {
            pair<int, vector<string>> result = minimaxPath(child, depth - 1, false);
            int eval = result.first;
            vector<string> path = result.second;
            if (eval > maxEval) {
                maxEval = eval;
                bestPath = path;
                bestPath.insert(bestPath.begin(), child.name);
            }
        }
        return {maxEval, bestPath};
    } else {
        int minEval = INT_MAX;
        vector<string> bestPath;
        for (const auto& child : node.children) {
            pair<int, vector<string>> result = minimaxPath(child, depth - 1, true);
            int eval = result.first;
            vector<string> path = result.second;
            if (eval < minEval) {
                minEval = eval;
                bestPath = path;
                bestPath.insert(bestPath.begin(), child.name);
            }
        }
        return {minEval, bestPath};
    }
}

int main() {
    // Leaves
    Node d1("d1", -1), d2("d2", 8);
    Node e1("e1", -3), e2("e2", -1);
    Node f1("f1", 2), f2("f2", 1);
    Node g1("g1", -3), g2("g2", 4);

    // Internal nodes
    Node D("D", 0, {d1, d2});
    Node E("E", 0, {e1, e2});
    Node F("F", 0, {f1, f2});
    Node G("G", 0, {g1, g2});

    // Level B and C
    Node B("B", 0, {D, E});
    Node C("C", 0, {F, G});

    // Root A
    Node A("A", 0, {B, C});

    // Depth of the tree is 3
    pair<int, vector<string>> result = minimaxPath(A, 3, true);
    int optimalValue = result.first;
    vector<string> path = result.second;

    cout << "Optimal value at root (A): " << optimalValue << endl;

    cout << "Path: A "; // root always included
    for (string n : path) cout << "-> " << n << " ";
    cout << endl;

    return 0;
}

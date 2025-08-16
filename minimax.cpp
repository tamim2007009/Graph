#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int value;              
    vector<Node> children;  

    Node(int val) { // Leaf node
        value = val;
    }

    Node(int val, vector<Node> childs) { // Internal node
        value = val;
        children = childs;
    }
};

int minimax(const Node& node, int depth, bool maximizingPlayer) {
    if (depth == 0 || node.children.empty()) {
        return node.value;
    }

    if (maximizingPlayer) {
        int maxEval = INT_MIN;
        for (const auto& child : node.children) {
            int eval = minimax(child, depth - 1, false);
            maxEval = max(maxEval, eval);
        }
        return maxEval;
    } else {
        int minEval = INT_MAX;
        for (const auto& child : node.children) {
            int eval = minimax(child, depth - 1, true);
            minEval = min(minEval, eval);
        }
        return minEval;
    }
}

int main() {
    // Leaves
    Node d1(-1), d2(8);
    Node e1(-3),e2(-1);
    Node f1(2), f2(1);
    Node g1(-3), g2(4);

    // Internal nodes
    Node D(0, {d1, d2});
    Node E(0, {e1,e2});
    Node F(0, {f1, f2});
    Node G(0, {g1, g2});

    // Level B and C
    Node B(0, {D, E});
    Node C(0, {F, G});

    // Root A
    Node A(0, {B, C});

    // Depth of the tree is 3
    int optimalValue = minimax(A, 3, true);

    cout << "Optimal value at root (A): " << optimalValue << endl;

    return 0;
}

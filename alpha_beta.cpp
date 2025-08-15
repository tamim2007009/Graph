#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int value;
    vector<Node> children;

    Node(int val) : value(val) {}
    Node(int val, vector<Node> childs) : value(val), children(childs) {}
};

int minimax(const Node& node, int depth, bool maximizingPlayer, int alpha, int beta) {
    if (depth == 0 || node.children.empty())
        return node.value;

    if (maximizingPlayer) {
        int maxEval = INT_MIN;
        for (const auto& child : node.children) {
            int eval = minimax(child, depth - 1, false, alpha, beta);
            maxEval = max(maxEval, eval);
            alpha = max(alpha, eval);
            if (beta <= alpha)
                break; // Beta cutoff
        }
        return maxEval;
    } else {
        int minEval = INT_MAX;
        for (const auto& child : node.children) {
            int eval = minimax(child, depth - 1, true, alpha, beta);
            minEval = min(minEval, eval);
            beta = min(beta, eval);
            if (beta <= alpha)
                break; // Alpha cutoff
        }
        return minEval;
    }
}

int main() {
    Node leafA1(3), leafA2(5);
    Node leafB1(6), leafB2(9);
    Node leafC1(1), leafC2(2);

    Node nodeA(0, {leafA1, leafA2});
    Node nodeB(0, {leafB1, leafB2});
    Node nodeC(0, {leafC1, leafC2});

    Node root(0, {nodeA, nodeB, nodeC});

    int optimalValue = minimax(root, 2, true, INT_MIN, INT_MAX);
    cout << "Optimal value: " << optimalValue << endl;

    return 0;
}

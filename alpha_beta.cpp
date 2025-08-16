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
    // Leaves (bottom of the tree)
    Node n1(3), n2(4), n3(2), n4(1),
         n5(7), n6(8), n7(9), n8(10),
         n9(2), n10(11), n11(1), n12(12),
         n13(14), n14(9), n15(13), n16(16);

    // Build level above leaves (Min nodes)
    Node min1(0, {n1, n2});
    Node min2(0, {n3, n4});
    Node min3(0, {n5, n6});
    Node min4(0, {n7, n8});
    Node min5(0, {n9, n10});
    Node min6(0, {n11, n12});
    Node min7(0, {n13, n14});
    Node min8(0, {n15, n16});

    // Build next level (Max nodes)
    Node max1(0, {min1, min2});
    Node max2(0, {min3, min4});
    Node max3(0, {min5, min6});
    Node max4(0, {min7, min8});

    // Build next level (Min nodes)
    Node min9(0, {max1, max2});
    Node min10(0, {max3, max4});

    // Root (Max node)
    Node root(0, {min9, min10});

    // Run minimax with alpha-beta
    int optimalValue = minimax(root, 4, true, INT_MIN, INT_MAX);

    cout << "Optimal value: " << optimalValue << endl;

    return 0;
}

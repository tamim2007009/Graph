#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int value;              // Utility value if it's a leaf node
    vector<Node> children;  // Possible moves from this state

    // Constructor for leaf nodes
    Node(int val){
        value=val;
    }

    // Constructor for internal nodes
    Node(int val, vector<Node> childs) {
        value=val;
        children=childs;
    }
};

int minimax(const Node& node, int depth, bool maximizingPlayer) {
    // Base case: leaf node or depth limit reached
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
    } 
    else { // Minimizing player
        int minEval = INT_MAX;
        for (const auto& child : node.children) {
            int eval = minimax(child, depth - 1, true);
            minEval = min(minEval, eval);
        }
        return minEval;
    }
}

int main() {
    // Creating the game tree:
    //         ROOT
    //        /    \
    //      A        B
    //     / \      / \
    //    3   5    2   9
    Node leaf1(3);
    Node leaf2(5);
    Node leaf3(2);
    Node leaf4(9);
    Node x(4);

    Node nodeA(0, {leaf1, leaf2});
    Node nodeB(0, {leaf3, leaf4});

    Node root(0, {nodeA, nodeB});

    // Find the optimal value starting from the root as the maximizing player
    int optimalValue = minimax(root, 2, true);

    cout << "Optimal value: " << optimalValue << endl; // Should output 5

    return 0;
}

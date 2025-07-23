#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    
    Node(int v) : val(v), left(nullptr), right(nullptr) {}
};

Node* buildTree(vector<tuple<int, int, char>>& edges) {
    map<int, Node*> nodes;
    set<int> children;
    
    for (auto& edge : edges) {
        int parent = get<0>(edge);
        int child = get<1>(edge);
        char side = get<2>(edge);
        
        if (nodes.find(parent) == nodes.end()) {
            nodes[parent] = new Node(parent);
        }
        if (nodes.find(child) == nodes.end()) {
            nodes[child] = new Node(child);
        }
        
        children.insert(child);
        
        if (side == 'L') {
            nodes[parent]->left = nodes[child];
        } else {
            nodes[parent]->right = nodes[child];
        }
    }
    
    int root = -1;
    for (auto& pair : nodes) {
        if (children.find(pair.first) == children.end()) {
            root = pair.first;
            break;
        }
    }
    
    return nodes[root];
}

void levelOrder(Node* root) {
    if (!root) return;
    
    queue<Node*> q;
    q.push(root);
    
    bool first = true;
    while (!q.empty()) {
        Node* current = q.front();
        q.pop();
        
        if (!first) cout << " ";
        cout << current->val;
        first = false;
        
        if (current->left) q.push(current->left);
        if (current->right) q.push(current->right);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        vector<tuple<int, int, char>> edges;
        
        for (int i = 0; i < n; i++) {
            int u, v;
            char x;
            cin >> u >> v >> x;
            edges.push_back(make_tuple(u, v, x));
        }
        
        Node* root = buildTree(edges);
        levelOrder(root);
        cout << endl;
    }
    
    return 0;
} 
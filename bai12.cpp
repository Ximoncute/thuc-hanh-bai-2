#include <bits/stdc++.h>
using namespace std;

struct BIT {
    vector<int> tree;
    int n;
    
    BIT(int size) {
        n = size;
        tree.assign(n + 1, 0);
    }
    
    void update(int idx, int val) {
        for (int i = idx; i <= n; i += i & (-i)) {
            tree[i] = max(tree[i], val);
        }
    }
    
    int query(int idx) {
        int res = 0;
        for (int i = idx; i > 0; i -= i & (-i)) {
            res = max(res, tree[i]);
        }
        return res;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    vector<pair<int, int>> pairs(n);
    vector<int> y_coords;
    
    for (int i = 0; i < n; i++) {
        cin >> pairs[i].first >> pairs[i].second;
        y_coords.push_back(pairs[i].second);
    }
    
    // Sort pairs by x-coordinate first, then by y-coordinate
    sort(pairs.begin(), pairs.end());
    
    // Coordinate compression for y-coordinates
    sort(y_coords.begin(), y_coords.end());
    y_coords.erase(unique(y_coords.begin(), y_coords.end()), y_coords.end());
    
    int m = y_coords.size();
    BIT bit(m);
    
    int ans = 0;
    
    for (int i = 0; i < n; i++) {
        int y = pairs[i].second;
        
        // Find compressed coordinate for y
        int y_idx = lower_bound(y_coords.begin(), y_coords.end(), y) - y_coords.begin() + 1;
        
        // Query for maximum LIS ending before current y
        int current_lis = bit.query(y_idx - 1) + 1;
        
        // Update BIT with current LIS value
        bit.update(y_idx, current_lis);
        
        ans = max(ans, current_lis);
    }
    
    cout << ans << endl;
    
    return 0;
} 
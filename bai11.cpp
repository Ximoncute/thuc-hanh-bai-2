#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        vector<vector<int>> c(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> c[i][j];
            }
        }
        
        vector<vector<int>> dp(1 << n, vector<int>(n, INT_MAX));
        
        dp[1][0] = 0;
        
        for (int mask = 1; mask < (1 << n); mask++) {
            for (int u = 0; u < n; u++) {
                if (!(mask & (1 << u)) || dp[mask][u] == INT_MAX) continue;
                
                for (int v = 0; v < n; v++) {
                    if (mask & (1 << v)) continue;
                    
                    int new_mask = mask | (1 << v);
                    dp[new_mask][v] = min(dp[new_mask][v], dp[mask][u] + c[u][v]);
                }
            }
        }
        
        int ans = INT_MAX;
        int full_mask = (1 << n) - 1;
        for (int u = 0; u < n; u++) {
            if (dp[full_mask][u] != INT_MAX) {
                ans = min(ans, dp[full_mask][u]);
            }
        }
        
        cout << ans << endl;
    }
    
    return 0;
} 
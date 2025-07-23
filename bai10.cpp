#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while (t--) {
        int n, s;
        cin >> n >> s;
        
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        vector<vector<bool>> dp(n + 1, vector<bool>(s + 1, false));
        
        for (int i = 0; i <= n; i++) {
            dp[i][0] = true;
        }
        
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= s; j++) {
                dp[i][j] = dp[i-1][j];
                if (j >= a[i-1]) {
                    dp[i][j] = dp[i][j] || dp[i-1][j-a[i-1]];
                }
            }
        }
        
        if (dp[n][s]) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    
    return 0;
} 
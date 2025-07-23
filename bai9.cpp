#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        int a[1000];
        int sorted_a[1000];
        
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            sorted_a[i] = a[i];
        }
        
        sort(sorted_a, sorted_a + n);
        
        int lis_length = 0;
        int dp[1000];
        
        for (int i = 0; i < n; i++) {
            dp[i] = 1;
            for (int j = 0; j < i; j++) {
                if (a[j] <= a[i]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            lis_length = max(lis_length, dp[i]);
        }
        
        cout << n - lis_length << endl;
    }
    
    return 0;
} 
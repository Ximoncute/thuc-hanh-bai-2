#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while (t--) {
        int n, k;
        cin >> n >> k;
        
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        sort(a.begin(), a.end());
        
        long long count = 0;
        for (int i = 0; i < n - 1; i++) {
            int target = a[i] + k;
            int pos = lower_bound(a.begin() + i + 1, a.end(), target) - a.begin();
            count += pos - i - 1;
        }
        
        cout << count << endl;
    }
    
    return 0;
} 
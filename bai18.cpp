#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while (t--) {
        int k;
        string s;
        cin >> k >> s;
        
        map<char, int> freq;
        for (char c : s) {
            freq[c]++;
        }
        
        priority_queue<int> pq;
        for (auto& pair : freq) {
            pq.push(pair.second);
        }
        
        for (int i = 0; i < k; i++) {
            if (!pq.empty()) {
                int maxFreq = pq.top();
                pq.pop();
                if (maxFreq > 1) {
                    pq.push(maxFreq - 1);
                }
            }
        }
        
        long long result = 0;
        while (!pq.empty()) {
            int freq = pq.top();
            pq.pop();
            result += (long long)freq * freq;
        }
        
        cout << result << endl;
    }
    
    return 0;
} 
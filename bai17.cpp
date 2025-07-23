#include <bits/stdc++.h>
using namespace std;

vector<string> generateLuckyNumbers(int n) {
    vector<string> result;
    queue<string> q;
    
    q.push("6");
    q.push("8");
    
    while (!q.empty()) {
        string current = q.front();
        q.pop();
        
        if (current.length() <= n) {
            result.push_back(current);
            
            if (current.length() < n) {
                q.push(current + "6");
                q.push(current + "8");
            }
        }
    }
    
    sort(result.begin(), result.end(), [](const string& a, const string& b) {
        if (a.length() != b.length()) {
            return a.length() > b.length();
        }
        return a > b;
    });
    
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        vector<string> luckyNumbers = generateLuckyNumbers(n);
        
        cout << luckyNumbers.size() << endl;
        
        for (int i = 0; i < luckyNumbers.size(); i++) {
            if (i > 0) cout << " ";
            cout << luckyNumbers[i];
        }
        cout << endl;
    }
    
    return 0;
} 
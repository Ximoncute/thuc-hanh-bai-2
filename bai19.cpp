#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n) {
    if (n < 2) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

vector<int> getNeighbors(int num) {
    vector<int> neighbors;
    string s = to_string(num);
    
    for (int pos = 0; pos < 4; pos++) {
        char original = s[pos];
        
        for (char digit = '0'; digit <= '9'; digit++) {
            if (digit == original) continue;
            if (pos == 0 && digit == '0') continue;
            
            s[pos] = digit;
            int newNum = stoi(s);
            
            if (newNum >= 1000 && newNum <= 9999 && isPrime(newNum)) {
                neighbors.push_back(newNum);
            }
        }
        
        s[pos] = original;
    }
    
    return neighbors;
}

int minSteps(int start, int target) {
    if (start == target) return 0;
    
    queue<pair<int, int>> q;
    set<int> visited;
    
    q.push({start, 0});
    visited.insert(start);
    
    while (!q.empty()) {
        int current = q.front().first;
        int steps = q.front().second;
        q.pop();
        
        vector<int> neighbors = getNeighbors(current);
        
        for (int neighbor : neighbors) {
            if (neighbor == target) {
                return steps + 1;
            }
            
            if (visited.find(neighbor) == visited.end()) {
                visited.insert(neighbor);
                q.push({neighbor, steps + 1});
            }
        }
    }
    
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while (t--) {
        int s, target;
        cin >> s >> target;
        
        cout << minSteps(s, target) << endl;
    }
    
    return 0;
} 
#include <iostream>
using namespace std;

long long getLength(int n) {
    if (n == 1) return 1;
    return 2 * getLength(n-1) + 1;
}

char findChar(int n, long long k) {
    if (n == 1) return 'A';
    
    long long prevLen = getLength(n-1);
    
    if (k <= prevLen) {
        return findChar(n-1, k);
    } else if (k == prevLen + 1) {
        return 'A' + n - 1;
    } else {
        return findChar(n-1, k - prevLen - 1);
    }
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        long long k;
        cin >> n >> k;
        
        cout << findChar(n, k) << endl;
    }
    
    return 0;
} 
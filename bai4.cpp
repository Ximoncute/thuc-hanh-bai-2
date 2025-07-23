#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    int a[1001];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    int minSum = 999999999;
    
    for (int k = 1; k <= 2000; k++) {
        int b[1001];
        bool valid = true;
        int sum = 0;
        
        for (int i = 0; i < n; i++) {
            b[i] = -1;
            for (int j = 1; j <= 2000; j++) {
                if (a[i] / j == k) {
                    b[i] = j;
                    break;
                }
            }
            if (b[i] == -1) {
                valid = false;
                break;
            }
            sum += b[i];
        }
        
        if (valid && sum < minSum) {
            minSum = sum;
        }
    }
    
    cout << minSum << endl;
    
    return 0;
} 
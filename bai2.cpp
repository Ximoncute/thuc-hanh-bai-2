#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n, s, m;
        cin >> n >> s >> m;
        
        int total_food = s * m;
        
        int sundays = 0;
        for (int day = 1; day <= s; day++) {
            if (day % 7 == 0) {
                sundays++;
            }
        }
        
        int buy_days = s - sundays;
        
        if (buy_days * n < total_food) {
            cout << -1 << endl;
        } else {
            int days_needed = (total_food + n - 1) / n;
            cout << days_needed << endl;
        }
    }
    
    return 0;
} 
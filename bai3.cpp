#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Job {
    int id, deadline, profit;
};

bool compare(Job a, Job b) {
    return a.profit > b.profit;
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        vector<Job> jobs(n);
        for (int i = 0; i < n; i++) {
            cin >> jobs[i].id >> jobs[i].deadline >> jobs[i].profit;
        }
        
        sort(jobs.begin(), jobs.end(), compare);
        
        int maxDeadline = 0;
        for (int i = 0; i < n; i++) {
            maxDeadline = max(maxDeadline, jobs[i].deadline);
        }
        
        vector<bool> slot(maxDeadline + 1, false);
        int jobCount = 0;
        int totalProfit = 0;
        
        for (int i = 0; i < n; i++) {
            for (int j = jobs[i].deadline; j >= 1; j--) {
                if (!slot[j]) {
                    slot[j] = true;
                    jobCount++;
                    totalProfit += jobs[i].profit;
                    break;
                }
            }
        }
        
        cout << jobCount << " " << totalProfit << endl;
    }
    
    return 0;
} 
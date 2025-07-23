#include <iostream>
#include <string>
using namespace std;

long long binaryToDecimal(string binary) {
    long long result = 0;
    long long power = 1;
    
    for (int i = binary.length() - 1; i >= 0; i--) {
        if (binary[i] == '1') {
            result += power;
        }
        power *= 2;
    }
    
    return result;
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        string s1, s2;
        cin >> s1 >> s2;
        
        long long num1 = binaryToDecimal(s1);
        long long num2 = binaryToDecimal(s2);
        
        cout << num1 * num2 << endl;
    }
    
    return 0;
} 
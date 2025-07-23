#include <bits/stdc++.h>
using namespace std;

int evaluate(string exp) {
    stack<int> st;
    
    for (int i = exp.length() - 1; i >= 0; i--) {
        char c = exp[i];
        
        if (isdigit(c)) {
            st.push(c - '0');
        } else {
            int operand1 = st.top(); st.pop();
            int operand2 = st.top(); st.pop();
            
            int result;
            switch (c) {
                case '+':
                    result = operand1 + operand2;
                    break;
                case '-':
                    result = operand1 - operand2;
                    break;
                case '*':
                    result = operand1 * operand2;
                    break;
                case '/':
                    result = operand1 / operand2;
                    break;
            }
            
            st.push(result);
        }
    }
    
    return st.top();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while (t--) {
        string exp;
        cin >> exp;
        
        cout << evaluate(exp) << endl;
    }
    
    return 0;
} 
#include <bits/stdc++.h>
using namespace std;

string postfixToPrefix(string postfix) {
    stack<string> st;
    
    for (int i = 0; i < postfix.length(); i++) {
        char c = postfix[i];
        
        if (isalnum(c)) {
            st.push(string(1, c));
        } else {
            string operand2 = st.top(); st.pop();
            string operand1 = st.top(); st.pop();
            
            string result = c + operand1 + operand2;
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
        
        cout << postfixToPrefix(exp) << endl;
    }
    
    return 0;
} 
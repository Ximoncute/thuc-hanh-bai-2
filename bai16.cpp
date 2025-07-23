#include <bits/stdc++.h>
using namespace std;

struct Node {
    int coeff;
    int exp;
    Node* next;
    
    Node(int c, int e) : coeff(c), exp(e), next(nullptr) {}
};

class Polynomial {
public:
    Node* head;
    
    Polynomial() : head(nullptr) {}
    
    void insert(int coeff, int exp) {
        Node* newNode = new Node(coeff, exp);
        if (!head || head->exp < exp) {
            newNode->next = head;
            head = newNode;
        } else {
            Node* current = head;
            while (current->next && current->next->exp > exp) {
                current = current->next;
            }
            if (current->exp == exp) {
                current->coeff += coeff;
                delete newNode;
            } else {
                newNode->next = current->next;
                current->next = newNode;
            }
        }
    }
    
    void parseAndInsert(string poly) {
        stringstream ss(poly);
        string term;
        
        while (getline(ss, term, '+')) {
            term.erase(0, term.find_first_not_of(" "));
            term.erase(term.find_last_not_of(" ") + 1);
            
            int coeff = 0, exp = 0;
            size_t pos = term.find("*x^");
            
            if (pos != string::npos) {
                coeff = stoi(term.substr(0, pos));
                exp = stoi(term.substr(pos + 3));
            }
            
            insert(coeff, exp);
        }
    }
    
    Polynomial add(const Polynomial& other) {
        Polynomial result;
        Node* p1 = head;
        Node* p2 = other.head;
        
        while (p1 && p2) {
            if (p1->exp > p2->exp) {
                result.insert(p1->coeff, p1->exp);
                p1 = p1->next;
            } else if (p1->exp < p2->exp) {
                result.insert(p2->coeff, p2->exp);
                p2 = p2->next;
            } else {
                int sum = p1->coeff + p2->coeff;
                if (sum != 0) {
                    result.insert(sum, p1->exp);
                }
                p1 = p1->next;
                p2 = p2->next;
            }
        }
        
        while (p1) {
            result.insert(p1->coeff, p1->exp);
            p1 = p1->next;
        }
        
        while (p2) {
            result.insert(p2->coeff, p2->exp);
            p2 = p2->next;
        }
        
        return result;
    }
    
    void print() {
        if (!head) return;
        
        Node* current = head;
        bool first = true;
        
        while (current) {
            if (!first && current->coeff > 0) {
                cout << " + ";
            }
            if (first && current->coeff < 0) {
                cout << "-";
            }
            
            cout << abs(current->coeff) << "*x^" << current->exp;
            
            first = false;
            current = current->next;
            
            if (current && current->coeff < 0) {
                cout << " - ";
                current->coeff = abs(current->coeff);
            }
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    cin.ignore();
    
    while (t--) {
        string poly1, poly2;
        getline(cin, poly1);
        getline(cin, poly2);
        
        Polynomial p1, p2;
        p1.parseAndInsert(poly1);
        p2.parseAndInsert(poly2);
        
        Polynomial result = p1.add(p2);
        result.print();
        cout << endl;
    }
    
    return 0;
} 
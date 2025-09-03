#include <iostream>
using namespace std;

#define MAX 100

class Stack {
    char arr[MAX];
    int top;
public:
    Stack() { top = -1; }
    void push(char c) { arr[++top] = c; }
    char pop() { return arr[top--]; }
    bool isEmpty() { return top == -1; }
};

bool isBalanced(string expr) {
    Stack s;
    for (char c : expr) {
        if (c == '(' || c == '{' || c == '[') {
            s.push(c);
        } else if (c == ')' || c == '}' || c == ']') {
            if (s.isEmpty()) return false;
            char top = s.pop();
            if ((c == ')' && top != '(') ||
                (c == '}' && top != '{') ||
                (c == ']' && top != '[')) {
                return false;
            }
        }
    }
    return s.isEmpty();
}

int main() {
    string expr;
    cout << "Enter expression: ";
    cin >> expr;

    if (isBalanced(expr))
        cout << "Balanced" << endl;
    else
        cout << "Not Balanced" << endl;

    return 0;
}

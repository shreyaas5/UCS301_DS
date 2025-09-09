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
    char peek() { return arr[top]; }
    bool isEmpty() { return top == -1; }
};

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}

string infixToPostfix(string infix) {
    Stack s;
    string postfix = "";

    for (int i = 0; i < infix.length(); i++) {
        char c = infix[i];

        if (isalnum(c)) {
            postfix += c;   
        }
        else if (c == '(') {
            s.push(c);
        }
        else if (c == ')') {
            while (!s.isEmpty() && s.peek() != '(') {
                postfix += s.pop();
            }
            s.pop(); 
        }
        else { 
            while (!s.isEmpty() && precedence(s.peek()) >= precedence(c)) {
                postfix += s.pop();
            }
            s.push(c);
        }
    }

    while (!s.isEmpty()) {
        postfix += s.pop();
    }

    return postfix;
}

int main() {
    string infix;
    cout << "Enter infix expression: ";
    cin >> infix;

    cout << "Postfix expression: " << infixToPostfix(infix) << endl;

    return 0;
}

#include <iostream>
using namespace std;

#define MAX 100

class IntStack {
    int arr[MAX];
    int top;
public:
    IntStack() { top = -1; }
    void push(int x) { arr[++top] = x; }
    int pop() { return arr[top--]; }
    bool isEmpty() { return top == -1; }
};

int evaluatePostfix(string postfix) {
    IntStack s;

    for (int i = 0; i < postfix.length(); i++) {
        char c = postfix[i];

        if (isdigit(c)) {
            s.push(c - '0'); 
        }
        else {
            int val2 = s.pop();
            int val1 = s.pop();
            switch (c) {
                case '+': s.push(val1 + val2); break;
                case '-': s.push(val1 - val2); break;
                case '*': s.push(val1 * val2); break;
                case '/': s.push(val1 / val2); break;
            }
        }
    }
    return s.pop();
}

int main() {
    string postfix;
    cout << "Enter postfix expression (single-digit operands): ";
    cin >> postfix;

    cout << "Evaluation result: " << evaluatePostfix(postfix) << endl;

    return 0;
}

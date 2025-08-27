#include <iostream>
#include <cstring>
using namespace std;

#define MAX 50 

class CharStack {
    char arr[MAX];
    int top;
public:
    CharStack() { top = -1; }

    void push(char c) {
        if (top == MAX - 1) {
            cout << "Stack Overflow!" << endl;
            return;
        }
        arr[++top] = c;
    }

    char pop() {
        if (top == -1) {
            cout << "Stack Underflow!" << endl;
            return '\0';
        }
        return arr[top--];
    }

    bool isEmpty() {
        return top == -1;
    }
};

int main() {
    char str[100];
    cout << "Enter a string: ";
    cin.getline(str, 100);

    CharStack s;
    int len = strlen(str);

    for (int i = 0; i < len; i++) {
        s.push(str[i]);
    }

    cout << "Reversed string: ";
    while (!s.isEmpty()) {
        cout << s.pop();
    }
    cout << endl;

    return 0;
}

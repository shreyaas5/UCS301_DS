#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char str[5][50], temp[50];

    cout << "Enter 5 strings: " << endl;
    for (int i = 0; i < 5; i++) {
        cin >> str[i];
    }

    // Bubble sort 
    for (int i = 0; i < 5; i++) {
        for (int j = i + 1; j < 5; j++) {
            if (strcmp(str[i], str[j]) > 0) {
                strcpy(temp, str[i]);
                strcpy(str[i], str[j]);
                strcpy(str[j], temp);
            }
        }
    }

    cout << "Strings in alphabetical order: " << endl;
    for (int i = 0; i < 5; i++) {
        cout << str[i] << endl;
    }

    return 0;
}

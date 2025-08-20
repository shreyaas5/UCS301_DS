#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter size of tri-diagonal matrix: ";
    cin >> n;

    int size = 3*n - 2;
    int tri[size];

    cout << "Enter elements of tri-diagonal matrix (row by row): " << endl;
    int k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int x;
            cin >> x;
            if (i == j || i == j+1 || i == j-1) {
                tri[k++] = x; 
            }
        }
    }

    cout << "Stored tri-diagonal elements: ";
    for (int i = 0; i < size; i++) {
        cout << tri[i] << " ";
    }
    cout << endl;

    cout << "Reconstructed matrix: " << endl;
    k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j || i == j+1 || i == j-1) {
                cout << tri[k++] << " ";
            } else {
                cout << 0 << " ";
            }
        }
        cout << endl;
    }

    return 0;
}

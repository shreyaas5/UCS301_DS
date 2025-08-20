#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter size of symmetric matrix: ";
    cin >> n;

    int size = n * (n + 1) / 2;
    int arr[size];

    cout << "Enter lower triangular elements row by row: " << endl ;
    int k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            cin >> arr[k++];
        }
    }

    cout << "Reconstructed symmetric matrix: " << endl ;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i >= j) {
                cout << arr[i*(i+1)/2 + j] << " ";
            } else {
                cout << arr[j*(j+1)/2 + i] << " ";
            }
        }
        cout << endl;
    }
    return 0;
}

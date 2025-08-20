#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter size of upper triangular matrix: ";
    cin >> n;

    int size = n * (n + 1) / 2;
    int arr[size];

    cout << "Enter upper triangular elements row by row: " << endl ;
    int k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            cin >> arr[k++];
        }
    }

    cout << "Reconstructed matrix: " << endl ;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i <= j) {
                int index = i*n - (i*(i-1))/2 + (j - i);
                cout << arr[index] << " ";
            } else {
                cout << 0 << " ";
            }
        }
        cout << endl;
    }
    return 0;
}

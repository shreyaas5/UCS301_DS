//Q4
#include <iostream>
using namespace std;

int main() {
    int choice;
    while (true) {
        cout << "MENU" << endl;
        cout << "1. Reverse Array, 2. Matrix Multiplication, 3. Matrix Transpose, 4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: { 
                // Reverse Array
                int arr[100], n;
                cout << "Enter number of elements: ";
                cin >> n;
                cout << "Enter elements: ";
                for (int i = 0; i < n; i++) {
                    cin >> arr[i];
                }
                for (int i = 0; i < n/2; i++) {
                    int temp = arr[i];
                    arr[i] = arr[n - i - 1];
                    arr[n - i - 1] = temp;
                }
                cout << "Reversed array: ";
                for (int i = 0; i < n; i++) {
                    cout << arr[i] << " ";
                }
                cout << endl;
                break;
            }

            case 2: { 
                // Matrix Multiplication
                int A[10][10], B[10][10], C[10][10], r1, c1, r2, c2;
                cout << "Enter rows and columns of first matrix: ";
                cin >> r1 >> c1;
                cout << "Enter rows and columns of second matrix: ";
                cin >> r2 >> c2;
                if (c1 != r2) {
                    cout << "Matrix multiplication not possible" << endl;
                    break;
                }
                cout << "Enter first matrix:" << endl;
                for (int i = 0; i < r1; i++)
                    for (int j = 0; j < c1; j++)
                        cin >> A[i][j];
                cout << "Enter second matrix:" << endl;
                for (int i = 0; i < r2; i++)
                    for (int j = 0; j < c2; j++)
                        cin >> B[i][j];
                for (int i = 0; i < r1; i++) {
                    for (int j = 0; j < c2; j++) {
                        C[i][j] = 0;
                        for (int k = 0; k < c1; k++) {
                            C[i][j] += A[i][k] * B[k][j];
                        }
                    }
                }
                cout << "Result matrix:" << endl;
                for (int i = 0; i < r1; i++) {
                    for (int j = 0; j < c2; j++) {
                        cout << C[i][j] << " ";
                    }
                    cout << endl;
                }
                break;
            }

            case 3: { 
                // Matrix Transpose
                int A[10][10], T[10][10], r, c;
                cout << "Enter rows and columns: ";
                cin >> r >> c;
                cout << "Enter matrix:" << endl;
                for (int i = 0; i < r; i++)
                    for (int j = 0; j < c; j++)
                        cin >> A[i][j];
                for (int i = 0; i < r; i++) {
                    for (int j = 0; j < c; j++) {
                        T[j][i] = A[i][j];
                    }
                }
                cout << "Transpose matrix:"<< endl;
                for (int i = 0; i < c; i++) {
                    for (int j = 0; j < r; j++) {
                        cout << T[i][j] << " ";
                    }
                    cout << endl;
                }
                break;
            }

            case 4:
                return 0;

            default:
                cout << "Invalid choice" << endl;
        }
    }
}

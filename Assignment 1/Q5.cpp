//sum of rows n columns
#include <iostream>
using namespace std;

int main() {
    int arr[10][10];
    int rows, cols;

    cout << "Enter the number of rows: ";
    cin >> rows;

    cout << "Enter the number of columns: ";
    cin >> cols;

    cout << "Enter the elements of the matrix:" << endl;
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            cin >> arr[i][j];
        }
    }

    //sum of each row
    for(int i = 0; i < rows; i++) {
        int rowSum = 0;
        for(int j = 0; j < cols; j++) {
            rowSum += arr[i][j];
        }
        cout << "Sum of row " << i + 1 << ": " << rowSum << endl;
    }

    //sum of each column
    for(int j = 0; j < cols; j++) {
        int colSum = 0;
        for(int i = 0; i < rows; i++) {
            colSum += arr[i][j];
        }
        cout << "Sum of column " << j + 1 << ": " << colSum << endl;
    }

    return 0;
}

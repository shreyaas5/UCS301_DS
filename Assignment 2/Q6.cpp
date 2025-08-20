#include <iostream>
using namespace std;

#define MAX 100

void readSparse(int mat[][3], int &terms) {
    cout << "Enter number of rows, columns, and non-zero terms: ";
    cin >> mat[0][0] >> mat[0][1] >> terms;

    mat[0][2] = terms;
    cout << "Enter row, column, and value for each non-zero element:\n";
    for (int i = 1; i <= terms; i++) {
        cin >> mat[i][0] >> mat[i][1] >> mat[i][2];
    }
}

void displaySparse(int mat[][3]) {
    int rows = mat[0][0], cols = mat[0][1], terms = mat[0][2];
    cout << "Row Col Value\n";
    for (int i = 0; i <= terms; i++) {
        cout << mat[i][0] << " " << mat[i][1] << " " << mat[i][2] << endl;
    }
}

void transpose(int mat[][3], int trans[][3]) {
    int rows = mat[0][0], cols = mat[0][1], terms = mat[0][2];

    trans[0][0] = cols;
    trans[0][1] = rows;
    trans[0][2] = terms;

    int k = 1;
    for (int i = 0; i < cols; i++) {
        for (int j = 1; j <= terms; j++) {
            if (mat[j][1] == i) {
                trans[k][0] = mat[j][1];
                trans[k][1] = mat[j][0];
                trans[k][2] = mat[j][2];
                k++;
            }
        }
    }
}

void addSparse(int mat1[][3], int mat2[][3], int result[][3]) {
    if (mat1[0][0] != mat2[0][0] || mat1[0][1] != mat2[0][1]) {
        cout << "Addition not possible: dimensions differ " << endl ;
        return;
    }

    int t1 = mat1[0][2], t2 = mat2[0][2];
    result[0][0] = mat1[0][0];
    result[0][1] = mat1[0][1];
    int i = 1, j = 1, k = 1;

    while (i <= t1 && j <= t2) {
        if (mat1[i][0] < mat2[j][0] || 
           (mat1[i][0] == mat2[j][0] && mat1[i][1] < mat2[j][1])) {
            result[k][0] = mat1[i][0];
            result[k][1] = mat1[i][1];
            result[k][2] = mat1[i][2];
            i++; k++;
        }
        else if (mat2[j][0] < mat1[i][0] || 
                (mat2[j][0] == mat1[i][0] && mat2[j][1] < mat1[i][1])) {
            result[k][0] = mat2[j][0];
            result[k][1] = mat2[j][1];
            result[k][2] = mat2[j][2];
            j++; k++;
        }
        else { 
            result[k][0] = mat1[i][0];
            result[k][1] = mat1[i][1];
            result[k][2] = mat1[i][2] + mat2[j][2];
            i++; j++; k++;
        }
    }
    while (i <= t1) {
        result[k][0] = mat1[i][0];
        result[k][1] = mat1[i][1];
        result[k][2] = mat1[i][2];
        i++; k++;
    }
    while (j <= t2) {
        result[k][0] = mat2[j][0];
        result[k][1] = mat2[j][1];
        result[k][2] = mat2[j][2];
        j++; k++;
    }
    result[0][2] = k - 1;
}

void multiplySparse(int mat1[][3], int mat2[][3], int result[][3]) {
    if (mat1[0][1] != mat2[0][0]) {
        cout << "Multiplication not possible: dimensions mismatch\n";
        return;
    }

    int rows = mat1[0][0], cols = mat2[0][1];
    int t1 = mat1[0][2], t2 = mat2[0][2];

    int temp[MAX][3]; 
    int k = 0;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int sum = 0;
            for (int x = 1; x <= t1; x++) {
                if (mat1[x][0] == i) {
                    for (int y = 1; y <= t2; y++) {
                        if (mat2[y][1] == j && mat1[x][1] == mat2[y][0]) {
                            sum += mat1[x][2] * mat2[y][2];
                        }
                    }
                }
            }
            if (sum != 0) {
                temp[k][0] = i;
                temp[k][1] = j;
                temp[k][2] = sum;
                k++;
            }
        }
    }

    result[0][0] = rows;
    result[0][1] = cols;
    result[0][2] = k;
    for (int i = 1; i <= k; i++) {
        result[i][0] = temp[i-1][0];
        result[i][1] = temp[i-1][1];
        result[i][2] = temp[i-1][2];
    }
}

int main() {
    int mat1[MAX][3], mat2[MAX][3], trans[MAX][3], sum[MAX][3], prod[MAX][3];
    int terms1, terms2;

    cout << "Sparse Matrix 1:\n";
    readSparse(mat1, terms1);
    displaySparse(mat1);

    cout << "\nTranspose of Matrix 1:\n";
    transpose(mat1, trans);
    displaySparse(trans);

    cout << "\nSparse Matrix 2:\n";
    readSparse(mat2, terms2);
    displaySparse(mat2);

    cout << "\nAddition of Matrix 1 and Matrix 2:\n";
    addSparse(mat1, mat2, sum);
    displaySparse(sum);

    cout << "\nMultiplication of Matrix 1 and Matrix 2:\n";
    multiplySparse(mat1, mat2, prod);
    displaySparse(prod);

    return 0;
}

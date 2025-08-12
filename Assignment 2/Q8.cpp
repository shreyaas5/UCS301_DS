//count distinct
#include <iostream>
using namespace std;

int main() {
    int arr[] = {1, 2, 2, 3, 4, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int count = 0;
    for (int i = 0; i < n; i++) {
        int j;
        for (j = 0; j < i; j++) {
            if (arr[i] == arr[j]) break;
        }
        if (j == i) count++;
    }
    cout << "Number of distinct elements: " << count << endl;
    return 0;
}

//Missing element
#include <iostream>
using namespace std;

int main() {
    int arr[] = {1, 2, 3, 5, 6}; 
    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < n - 1; i++) {
        if (arr[i + 1] != arr[i] + 1) {
            cout << "The missing element is: " << arr[i] + 1 << endl;
        }
    }
    
    return 0;
}

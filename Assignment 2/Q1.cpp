//Binary Search
#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter the number of elements in the sorted array: ";
    cin >> n;

    int arr[100];
    cout << "Enter the sorted elements:" << endl;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int target;
    cout << "Enter the element to search: ";
    cin >> target;

    int low = 0, high = n - 1;
    int mid;
    int flag = 0;

    while(low <= high) {
        mid = (low + high) / 2;
        if(arr[mid] == target) {
            flag = 1;
            break;
        }
        else if(arr[mid] < target) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    if(flag ==1) {
        cout << "Element found at position: " << mid << endl;
    } else {
        cout << "Element not found in the array." << endl;
    }

    return 0;
}


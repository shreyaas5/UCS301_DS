// MENU driven code for operations on array
// 1.CREATE
// 2. DISPLAY
// 3. INSERT
// 4. DELETE
// 5. LINEAR SEARCH
// 6. EXIT

#include <iostream>
using namespace std;

int main(){
    int ch, arr[100], n = 0;
    while (true)
    {
        cout << "enter 1. create, 2. display, 3. insert, 4. delete, 5. Linear Search, 6. Exit";
        cin >> ch;
        switch(ch){
            case 1:
                cout << "enter number of elements : ";
                cin >> n;
                for (int i = 0; i < n; i++) {
                    cout << " enter element : ";
                    cin >> arr[i];
                }
                break;
            case 2:
                for (int i = 0; i < n; i++) {
                    cout << arr[i] << " ";
                }
                cout << endl;
                break;
            case 3: {
                int pos, val;
                cout << "enter position : ";
                cin >> pos;
                cout << "enter value : ";
                cin >> val;
                for (int i = n; i > pos; i--) {
                    arr[i] = arr[i - 1];
                }
                arr[pos] = val;
                n++;
                break;
            }
            case 4: {
                int pos;
                cout << "enter position : ";
                cin >> pos;
                for (int i = pos; i < n - 1; i++) {
                    arr[i] = arr[i + 1];
                }
                n--;
                break;
            }
            case 5: {
                int key;
                cout << "enter element to search : ";
                cin >> key;
                for (int i = 0; i < n; i++) {
                    if (arr[i] == key) {
                        cout << "Found at position " << i << endl;
                        break;
                    }
                    if (i == n - 1) {
                        cout << "Not found" << endl;
                    }
                }
                break;
            }
            case 6:
                return 0;
            default:
                break;
        }
    }
}

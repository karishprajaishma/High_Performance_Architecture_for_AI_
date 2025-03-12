#include <iostream>
using namespace std;

int main() {
    
    int a[2][3] = {{5, 6, 7}, {4, 5, 2}};
    int b[2][3] = {{3, 5, 1}, {10, 11, 12}};
    int c[2][3];


    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            c[i][j] = a[i][j] + b[i][j];
        }
    }

    cout << "RESULTANT MATRIX : " << endl;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            cout << c[i][j] << "\t";
        }
        cout << endl;
    }

    return 0;
}

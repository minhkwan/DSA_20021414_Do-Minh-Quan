#include <iostream>
using namespace std;

int a[20];
bool isValid(int x, int y) {
    for(int i =1; i < x; i++) {
        if(a[i] == y || abs(i-x) == abs(a[i] - y)) {
            return false;
        }
    }
    return true;
}

void Print(int n) {
    for(int i =1; i <= n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

void Try(int i, int n) {
    for(int j = 1; j <= n; j++) {
        if(isValid(i,j)) {
            a[i] = j;

            if(i == n){
                Print(n);
            }
            Try(i+1, n);
        }
    }
}
int main() {
    int n = 8;
    Try(1,n);
}

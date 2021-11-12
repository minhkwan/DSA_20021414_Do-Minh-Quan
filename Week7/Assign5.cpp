#include<iostream>
using namespace std;
void xuat(int a[], int n) {
    for (int i = 1; i <= n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

void Try(int k, bool used[], int a[], int n) {
    for(int i = 1; i <= n; i++) {
        if (!used[i]) {
            a[k] = i;
            used[i] = 1;
            if (k == n)
                xuat(a,n);
            else
                Try(k+1, used, a, n);
            used[i] = 0;
        }
    }
}

int main() {
    int n;
    cin >> n;
    int a[n];
    bool used[n] = { 0 };
    Try(1,used,a,n);
}


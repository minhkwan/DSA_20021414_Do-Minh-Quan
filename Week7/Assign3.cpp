#include <iostream>
using namespace std;
int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b,a%b);
}
int main() {
    int X,Y;
    cin >> X >> Y;
    cout << gcd(X,Y);
}

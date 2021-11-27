#include <iostream>
using namespace std;

struct Item {
    double m;
    double value;
    double valuePer;
};

void tinhDonGia(Item vat[], int n) {
    for(int i = 0; i < n; i++) {
        vat[i].valuePer = vat[i].value / vat[i].m;
    }
}

void SapXep(Item vat[], int n) {
    for(int i = 0; i < n - 1; i++) {
        for(int j = i+1; j < n; j++) {
            if(vat[i].valuePer < vat[j].valuePer) {
                swap(vat[i],vat[j]);
            }
        }
    }
}

double Greedy(Item vat[], int n, double W) {
    double result = 0;
    for(int i = 0; i < n; i++) {
        if(W <= 0) {
            return result;
        }
        result = result + vat[i].value;
        W = W - vat[i].m;
    }
    return result;
}
int main() {
    cout << "Capacity of bag: ";
    int n;
    cin >> n;
    cout << "Amount of items in the shop: ";
    int a;
    cin >> a;
    Item vat[a];
    for(int i = 0; i < a; i++) {
        cin >> vat[i].value >> vat[i].m;
    }
    tinhDonGia(vat, a);
    SapXep(vat,a);
    cout << Greedy(vat, a, n);

}

#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
        int denomination[]={10000,20000,50000,100000,200000,500000};
        int cash[6];
        for(int i=0; i<6; i++){
            cash[i]=0;
        }
        int i=5;
        while(i>=0){
            if(n >= denomination[i]);
            break;
            i--;
        }
        while(i>=0 && n > 0){
            cash[i]=n /denomination[i];
            n = n % denomination[i];
            i--;
        }
        cout << "So tien ban rut duoc la: " << endl;
        for(int i=5; i>=0; i--){
            if(cash[i]>0){
                cout << cash[i] << " to " << denomination[i] << endl;
            }
        }
}

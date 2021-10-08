#include <vector>
#include <iostream>
using namespace std;
vector <int> hashTable[100];
int hashTableSize = 100;

int hashFunc(int x) {
    return x % hashTableSize;
}

void insert(int x){
    int index = hashFunc(x);
    hashTable[index].push_back(x);
}

void search(int x) {
    int index = hashFunc(x);
    for(int i = 0; i < hashTable[index].size(); i++) {
        if(hashTable[index][i] == x) {
            cout << x << " is found." << endl;
            return;
        }
    }
    cout << x << " is not found.";
}

void remove(int x) {
    int index = hashFunc(x);
    for(int i = 0; i < hashTable[index].size(); i++) {
        if(hashTable[index][i] == x){
                hashTable[index].erase(hashTable[index].begin() + i);
        }
    }
}

int main(){
    int n;
    int temp;
    cin >> n;
    int *a = new int[n];
    for(int i = 0; i<n; i++){
        cin >> a[i];
        insert(a[i]);
    }
    cout << "Nhap so ban muon tim: " << endl;
    cin >> temp;
    search(temp);
    cout << "Nhap so ban muon xoa: " << endl;
    cin >> temp;
    remove(temp);
    search(temp);
}


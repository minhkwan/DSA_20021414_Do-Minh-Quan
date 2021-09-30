#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void printSet0(int n, int arr[]){
    sort(arr, arr + n);
    for(int i = 0; i < n - 1; i++){
        int j = i + 1;
        int e = n -1;
        int x = arr[i];
        while (j < e){
        if(x + arr[j] + arr[e] == 0)
            {
                cout << x << " " << arr[j] << " " << arr[e] << endl;
                break;
            }
        else if (x + arr[j] + arr[e] < 0){
            j++;
        }

        else if (x + arr[j] + arr[e] > 0){
            e--;
        }
        }
    }
}
int main(){
    int n;
    cin >> n;
    int *a = new int[n];
    for(int i = 0; i<n; i++){
        cin >> a[i];
    }
    printSet0(n,a);

}
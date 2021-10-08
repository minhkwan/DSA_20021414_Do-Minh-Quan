#include <iostream>
#include <map>
#include<bits/stdc++.h>
using namespace std;

void equalZero(int arr[], int n)
{
    bool found = false;

    for (int i=0; i<n-1; i++)
    {
        unordered_set<int> s;
        for (int j=i+1; j<n; j++)
        {
            int x = -(arr[i] + arr[j]);
            if (s.find(x) != s.end())
            {
                cout << x << " " << arr[i] << " " << arr[j] << endl;
                found = true;
            }
            else{
                s.insert(arr[j]);
        }}
    }

    if (found == false)
        cout << " No Triplet Found" << endl;
}

int main()
{
    int n;
    cin >> n;
    int *a = new int[n];
    for(int i = 0; i<n; i++){
        cin >> a[i];
    }
    equalZero(a,n);
}

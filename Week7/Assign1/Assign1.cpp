#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    vector<int> a;
    fstream fileInput("D:\\DSA\\Week7\\Assign1\\number.txt");
    while(!fileInput.eof()) {
        int n;
        fileInput >> n;
        a.push_back(n);
    }
    fileInput.close();
    sort(a.begin(),a.end());
    ofstream fileOutput("D:\\DSA\\Week7\\Assign1\\numbers.sorted.txt");
    for(int i = 0; i < a.size(); i++) {
        fileOutput << a[i] << " ";
    }
}

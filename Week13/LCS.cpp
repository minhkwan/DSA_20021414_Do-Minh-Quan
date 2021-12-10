#include <iostream>
using namespace std;
string LCS(string s1, string s2) {
    int m = s1.length();
    int n = s2.length();
    int len = 1;
    int row,col;
    int check[m+1][n+1];
    string result = "                                         ";
    for(int i = 0; i <= m; i++) {
        for(int j = 0; j <= n; j++) {
            if (i == 0 || j == 0) {
                check[i][j] = 0;
            }
            else if(s1[i-1] == s2[j-1]) {
                check[i][j] = check[i-1][j-1] + 1;
                if (len < check[i][j]) {
                len = check[i][j];
                row = i;
                col = j;
                }
            }
            else {
                check[i][j] = 0;
            }
    }
}
    while (check[row][col] != 0) {
        result[--len] = s1[row - 1];
        row--;
        col--;
    }
    return result;
}
int main() {
    string s1, s2;
    cin >> s1 >> s2;
    cout << LCS(s1,s2);
}

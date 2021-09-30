#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    stack<int> front, rear;
    int n;
    cin >> n;
    while(n--){
        int selection, x;
        cin >> selection;
        if(selection == 1){
            cin >> x;
            rear.push(x);
        }
        else{
            if(front.empty()){
                while(!rear.empty()){
                    front.push(rear.top());
                    rear.pop();
                }
            }
            
            if(!front.empty()){
                if(selection == 2){ front.pop();}
                if(selection == 3) {cout << front.top() << endl;}
            }
        }
    }
    return 0;
}

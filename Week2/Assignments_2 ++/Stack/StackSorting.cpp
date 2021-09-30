#include <iostream>
#include <stack>
using namespace std;

stack<int> sortStack(stack<int> &input)
{
    stack<int> tmpStack;
 
    while (!input.empty())
    {
        int tmp = input.top();
        input.pop();
 
        while (!tmpStack.empty() && tmpStack.top() > tmp)
        {
            input.push(tmpStack.top());
            tmpStack.pop();
        }

        tmpStack.push(tmp);
    }
 
    return tmpStack;
}

int main(){
    stack<int> input;
    int n;
    cin >> n;
    int x;
    while(n--){
        cin >> x;
        input.push(x);
    }
    stack<int> output = sortStack(input);
    for(int i = 0; i<n; i++){
        cout << output.top();
        output.pop();
    }
}
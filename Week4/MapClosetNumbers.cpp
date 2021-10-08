 #include <iostream>
 #include <map>
 #include <vector>
 #include <algorithm>
 using namespace std;

 map<int,int> closestNumbers(vector<int> arr) {
    sort(arr.begin(), arr.end());
    map<int,int> result;
    int diff = abs(arr[1] - arr[0]);
    for(int i = 2; i < arr.size(); i++){
        if(diff > abs(arr[i]-arr[i-1])){
            diff = abs(arr[i]-arr[i-1]);
        }
    }

    for(int i = 0; i < arr.size()-1; i++ ){
        if(diff == abs(arr[i+1]-arr[i])){
            result.insert(pair<int, int> (arr[i],arr[i+1]));
        }
    }
    return result;
}
 int main(){
     int n;
     cin >> n;
     vector<int> a(n);
     for(int i = 0; i<n; i++){
        cin >> a[i];
     }
    map<int, int> answer = closestNumbers(a);
     for(map<int,int>::iterator i = answer.begin();i!=answer.end();i++){
        cout << i->first << " " << i->second << " ";
     }
     return 0;

 }

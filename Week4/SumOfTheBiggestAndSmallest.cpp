#include <iostream>
#include <set>
using namespace std;
int findMax(set<int> my_set)
{
    int max_element;
    if (!my_set.empty())
        max_element = *(my_set.rbegin());
    return max_element;
}

int findMin(set<int> my_set)
{
    int min_element;
    if (!my_set.empty())
        min_element = *my_set.begin();
    return min_element;
}
int main(){
    set<int> s;
    int n;
     cin >> n;
     int *a = new int[n];
     for(int i = 0 ; i<n ;i++){
         cin >> a[i];
         s.insert(a[i]);
     }
     cout << findMax(s) + findMin(s);
}

#include <iostream>
using namespace std;
void get(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
}

int Count(int arr[], int n)
{
    int count = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] == arr[j])
            {
                count++;
            }
        }
    }
    return count;
}

int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];
    get(arr, n);
    cout << Count(arr, n);
}
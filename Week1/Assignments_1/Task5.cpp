#include <iostream>
using namespace std;

void Cin(int a[])
{
    for (int i = 0; i < 5; i++)
    {
        cin >> a[i];
    }
}

void Sorting(int a[])
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = i + 1; j < 5; j++)
        {
            if (a[i] > a[j])
            {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}

void Print(int a[])
{
    cout << a[0] + a[4];
}

int main()
{
    int *a = new int[5];
    Cin(a);
    Sorting(a);
    Print(a);
}
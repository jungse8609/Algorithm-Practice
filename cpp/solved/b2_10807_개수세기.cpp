// BOG 10807 개수 세기

#include <iostream>
#include <algorithm>
using namespace std;

int n, v;
int a[102] = {};

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for (int i=0; i<n; ++i)
    {
        cin >> a[i];
    }
    cin >> v;

    int result = 0;
    for (int i=0; i<n; ++i)
    {
        if (a[i] == v)
            result += 1;
    }

    cout << result;
}
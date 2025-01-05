// BOG 10871 B3 X보다 작은 정수수

#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    
    int n, x;
    cin >> n >> x;

    int a;;
    for (int i=0; i<n; ++i)
    {
        cin >> a;
        if (a < x)
            cout << a << ' ';
    }
}
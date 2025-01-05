// BOG 10808 알파벳 개수

#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    int a, b, c;
    cin >> a >> b >> c;

    int mul = a * b * c;
    int num[10];
    fill(num, num+10, 0);

    while (mul > 0)
    {
        int r = mul % 10;
        num[r] += 1;
        mul /= 10;
    }
    
    for (int i=0; i<10; ++i)
    {
        cout << num[i] << '\n';
    }
}
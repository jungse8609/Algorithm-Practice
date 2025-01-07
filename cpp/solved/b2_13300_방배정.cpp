// BOG 13300 방 배정

#include <iostream>
#include <algorithm>
using namespace std;

int n, k;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n >> k;

    int a[2][7] = {};
    while (n--)
    {
        int s, y;
        cin >> s >> y;
        a[s][y] += 1;
    }

    int result = 0;
    for (int i=0; i<2; ++i)
    {
        for (int j=1; j<=6; ++j)
        {
            result += (a[i][j] + (k - 1)) / k;
        }
    }

    cout << result;
}
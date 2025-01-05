// BOG 3273 두 수의 합

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    int n;
    cin >> n;

    int a[2000001] = {};
    vector<int> v(n);
    for (int i=0; i<n; ++i)
    {
        cin >> v[i];
        a[v[i]] += 1;
    }
    int x;
    cin >> x;

    int result = 0;
    for (int i=0; i<n; ++i)
    {
        // x를 만들기 위해 필요한 수
        int req = x - v[i];

        // 현재 수가 x보다 같거나 큰 경우는 제외
        if (req <= 0) continue;

        // 필요한 수의 개수를 결과값에 더함
        result += a[req];

        // 만약 필요한 수가 자기 자신이라면 자기를 제외해야함 
        if (req == v[i])
            result -= 1;
    }

    cout << result / 2;
}
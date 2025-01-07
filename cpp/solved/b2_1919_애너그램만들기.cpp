// BOG 1919 애너그램 만들기

#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    string a, b;
    cin >> a >> b;

    int t[26] = {};

    for (auto& e : a) t[e - 'a'] += 1;
    for (auto& e : b) t[e - 'a'] -= 1;

    int result = 0;
    for (int e : t)
    {
        result += abs(e);
    }

    cout << result;
}
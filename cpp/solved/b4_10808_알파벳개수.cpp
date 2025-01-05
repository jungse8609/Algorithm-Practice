// BOG 10808 알파벳 개수

#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    int a[26];
    fill(a, a + 26, 0);
    string s;
    cin >> s;

    for (int i=0; i<s.size(); ++i)
    {
        a[s[i] - 'a'] += 1;
    }

    for (int e : a)
        cout << e << ' ';
}
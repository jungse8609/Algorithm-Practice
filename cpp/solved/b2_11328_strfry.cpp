// BOG 11328 strfry

#include <iostream>
#include <algorithm>
using namespace std;

int n;

bool strfry(string& a, string& b)
{
    int a[26] = {};

    for (auto& e : a) a[e - 'a'] += 1;
    for (auto& e : b) a[e - 'a'] -= 1;

    for (int i : a)
        if (i != 0)
            return false;

    return true;
}

bool strfry_sol1(string& a, string& b)
{
    int achar[26] = {};
    int bchar[26] = {};

    for (char e : a) achar[e - 'a'] += 1;
    for (char e : b) bchar[e - 'a'] += 1;    

    for (int i=0; i<26; ++i)
    {
        if (achar[i] != bchar[i]) return false;
    }

    return true;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n;

    while (n--)
    {
        string a, b;
        cin >> a >> b;

        if (strfry(a, b))
        {
            cout << "Possible\n";
        }
        else
        {
            cout << "Impossible\n";
        }
    }
}
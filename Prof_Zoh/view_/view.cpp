#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(0);


    int n;
    cin >> n;

    pair<char, int> b[22];

    for (int i=0; i<n; ++i)
    {
        cin >> b[i].first >> b[i].second;
    }

    
    vector<char> mountain;
    mountain.push_back(b[0].first);
    int m_highest = b[0].second;
    for (int i=1; i<n; ++i)
    {
        if (m_highest < b[i].second)
        {
            mountain.push_back(b[i].first);
            m_highest = b[i].second;
        }
    }


    vector<char> sea;
    sea.push_back(b[n-1].first);
    int s_highest = b[n-1].second;
    for (int i=n-2; i>=0; --i)
    {
        if (s_highest < b[i].second)
        {
            sea.push_back(b[i].first);
            s_highest = b[i].second;
        }
    }

    reverse(sea.begin(), sea.end());

    for (auto& e : mountain)
        cout << e << ' ';

    cout << '\n';

    for (auto& e : sea)
        cout << e << ' ';
}
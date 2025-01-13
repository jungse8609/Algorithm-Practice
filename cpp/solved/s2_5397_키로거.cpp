// BOG 5397 키로거

#include <iostream>
#include <list>
using namespace std;

int main()
{
    cin.tie(0); ios::sync_with_stdio(0);

    int t;
    cin >> t;

    while (t--)
    {
        list<char> l;
        list<char>::iterator it = l.begin();
        string str; cin >> str;

        for (auto& e : str)
        {
            switch (e)
            {
            case '<':
                if (it != l.begin())
                    it--;
                break;
            case '>':
                if (it != l.end())
                    it++;
                break;
            case '-':
                if (it != l.begin())
                {
                    --it;
                    it = l.erase(it);
                }
                break;
            default:
                l.insert(it, e);
                break;
            }
        }

        for (auto& e : l)
            cout << e;
        cout << '\n';
    }
}
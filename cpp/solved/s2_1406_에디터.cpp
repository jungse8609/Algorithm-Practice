// BOG 1406 에디터

#include <iostream>
#include <list>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);

    string str; int n;
    cin >> str >> n;

    list<char> l;
    for (char e : str)
        l.push_back(e);

    list<char>::iterator it = l.end();

    while (n--)
    {
        char op, x;
        cin >> op;

        switch (op)
        {
        case 'L':
            if (it != l.begin())
                --it;
            break;
        case 'D':
            if (it != l.end())
                ++it;
            break;
        case 'B':
            if (it != l.begin())
            {
                --it;
                it = l.erase(it);
            }
            break;
        case 'P':
            cin >> x;
            l.insert(it, x);
            break;
        default:
            break;
        }
    }

    for (char e : l)
        cout << e;
}

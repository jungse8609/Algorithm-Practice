#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n, card; 
    cin >> n;

    vector<bool> v(n + 1);

    while (cin >> card) v[card] = 1;

    // O(N)
    for (card=1; card<=n; ++card)
        if (!v[card])
            cout << card <<'\n';
}
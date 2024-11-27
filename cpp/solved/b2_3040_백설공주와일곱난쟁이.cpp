// BOG B2 3040 백설공주와일곱난쟁이

#include <iostream>
#include <vector>
using namespace std;

int num[9];
vector<int> result;

void func(int start, vector<int> nan, int sum)
{
    if (nan.size() == 7)
    {
        // if sum == 100 return nan
        if (sum == 100) 
        {
            result = nan;
            return;
        }
        else return;
    }
    if (start >= 9) return;

    for (int i=start; i<9; ++i)
    {
        nan.push_back(num[i]);
        func(i + 1, nan, sum + num[i]);
        nan.pop_back();
    }
}

int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);

    // 9C7 = 36. Brute Force로 해결하면 끝
    
    for (int i=0; i<9; ++i)
        cin >> num[i];

    vector<int> vec = vector<int>();
    func(0, vec, 0);

    for (auto& e : result)
        cout << e << '\n';
}
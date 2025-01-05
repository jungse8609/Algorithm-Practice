// BOG 1475 방 번호

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    // 일단 인풋의 각 숫자 개수를 파악해
    // 6과 9에 대해서는 6과 9를 함께 생각해
    // 필요한 숫자 개수의 최댓값이 필요한 세트가 되겠지

    int n;
    cin >> n;
    vector<int> a(10, 0);

    while (n > 0)
    {
        a[n%10] += 1;
        n /= 10;
    }
    
    int result = -1;
    for (int i=0; i<10; ++i)
    {
        if (i == 6 || i == 9)
            continue;
        result = max(result, a[i]);
    }
    result = max(result, (a[6] + a[9] + 1) / 2);
    cout << result;
}
// BOG 1874 스택 수열

#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(0);

    int n; cin >> n;
    stack<int> s;
    queue<int> q;
    for (int i=1; i<=n; ++i)
    {
        int a; cin >> a;
        q.push(a);
    }

    string result = "";

    // 숫자 입력 받아
    // 만약 s.top()이 입력값이 아니다
    //      입력값까지 숫자를 추가해야 해
    for (int i=1; i<=n; ++i)
    {
        s.push(i);
        result += "+\n";

        // 같으면 계속 빼야지
        while (s.top() == q.front())
        {
            s.pop();
            q.pop();
            result += "-\n";

            if (s.empty())
                break;
        }
    }

    if (!s.empty())
    {
        cout << "NO";
    }
    else
    {
        cout << result;
    }
}
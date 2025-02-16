// BOG 1874 ���� ����

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

    // ���� �Է� �޾�
    // ���� s.top()�� �Է°��� �ƴϴ�
    //      �Է°����� ���ڸ� �߰��ؾ� ��
    for (int i=1; i<=n; ++i)
    {
        s.push(i);
        result += "+\n";

        // ������ ��� ������
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
// BOG 1874 ���� ����

#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n; cin >> n;
    stack<int> s;
    int cnt = 1;

    string result = "";
    while (n--)
    {
        int t; cin >> t;
        while (cnt <= t)
        {
            s.push(cnt++);
            result += "+\n";
        }
        if (s.top() != t)
        {
            cout << "NO";
            return 0;
        }

        s.pop();
        result += "-\n";
    }
    cout << result;    
}

// SOL 1
// int main()
// {
//     cin.tie(0); cout.tie(0);
//     ios::sync_with_stdio(0);

//     int n; cin >> n;
//     stack<int> s;
//     queue<int> q;
//     for (int i=1; i<=n; ++i)
//     {
//         int a; cin >> a;
//         q.push(a);
//     }

//     string result = "";

//     // ���� �Է� �޾�
//     // ���� s.top()�� �Է°��� �ƴϴ�
//     //      �Է°����� ���ڸ� �߰��ؾ� ��
//     for (int i=1; i<=n; ++i)
//     {
//         s.push(i);
//         result += "+\n";

//         // ������ ��� ������
//         while (s.top() == q.front())
//         {
//             s.pop();
//             q.pop();
//             result += "-\n";

//             if (s.empty())
//                 break;
//         }
//     }

//     if (!s.empty())
//     {
//         cout << "NO";
//     }
//     else
//     {
//         cout << result;
//     }
// }
// BOG 6198 ���� ���� �ٹ̱�

#include <iostream>
#include <stack>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    // stack�� �ִ� �ǹ����� ���� ���θ����� ���� �ǹ��� ����
    stack<int> s;
    long long result = 0;
    while (n--)
    {
        int h; cin >> h;
        // ���� �ǹ��� ������ �ֵ��� pop()
        while (!s.empty() && s.top() <= h)
            s.pop();
        // stack�� �����ִ� �ǹ��� ���� �ǹ��� ���� ������
        result += s.size();
        s.push(h);
    }
    cout << result;
}

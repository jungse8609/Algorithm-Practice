// BOG 2493 ž

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

struct tower
{
    tower() : i(0), n(0) {}
    tower(int _i, int _n)
    {
        i = _i;
        n = _n;
    }

    int i;
    int n;
};

int main()
{
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(0);

    // �ϳ��ϳ� Ž���ϴ°� ���� �ȵ�. O(N^N) �̴ϱ�
    
    /*
    �����ʺ��� stack ����
    (TOP <= ���� ����) �̸� POP, �̸� �ݺ�
    pair�� ���� (number, index) -> result ������ ���� index�� �Բ� ����

    ex) 6 9 5 7 3 4

    {(4, 5)}
    {(4, 5), (3, 4)}
    {(4, 5), (3, 4), (7, 3)} -> {(4, 5), (7, 3)} -> {(7, 3)} : result[4] = 4, result[5] = 4
    {(7, 3), (5, 2)}
    {(7, 3), (5, 2), (9, 1)} -> {(7, 3), (9, 1)} -> {(9, 1)} : result[2] = 2, result[3] = 2
    {(9, 1), (6, 0)}

    */

    int n; cin >> n;
    vector<int> v(n);
    for (auto& e : v)
        cin >> e;

    stack<tower> s;
    
    vector<int> result(n, 0);

    // �����ʿ��� ��������
    s.push(tower(n - 1, v[n - 1]));
    for (int i=n-2; i>=0; --i)
    {
        tower back = s.top();
        
        // ���� ���̺��� �۰ų� ���� �ǹ��� ��� ó������
        while (s.size() >= 1 && back.n <= v[i])
        {
            // n ��° Ÿ���� ����ϹǷ� �ε��� + 1 ���ش�
            result[back.i] = i + 1;
            s.pop();

            if (s.empty()) break;

            back = s.top();
        }

        s.push(tower(i, v[i]));
    }

    // �ᱣ�� ���
    for (auto& e : result)
        cout << e << ' ';
}
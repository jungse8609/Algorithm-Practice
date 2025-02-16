// BOG 2493 탑

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

    // 하나하나 탐색하는건 말이 안됨. O(N^N) 이니까
    
    /*
    오른쪽부터 stack 저장
    (TOP <= 현재 높이) 이면 POP, 이를 반복
    pair로 저장 (number, index) -> result 갱신을 위해 index도 함께 저장

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

    // 오른쪽에서 왼쪽으로
    s.push(tower(n - 1, v[n - 1]));
    for (int i=n-2; i>=0; --i)
    {
        tower back = s.top();
        
        // 현재 높이보다 작거나 같은 건물을 모두 처리해줌
        while (s.size() >= 1 && back.n <= v[i])
        {
            // n 번째 타워를 기록하므로 인덱스 + 1 해준다
            result[back.i] = i + 1;
            s.pop();

            if (s.empty()) break;

            back = s.top();
        }

        s.push(tower(i, v[i]));
    }

    // 결괏값 출력
    for (auto& e : result)
        cout << e << ' ';
}
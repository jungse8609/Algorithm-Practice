// BOG 6198 옥상 정원 꾸미기

#include <iostream>
#include <stack>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    // stack에 있는 건물들은 아직 가로막히지 않은 건물을 뜻함
    stack<int> s;
    long long result = 0;
    while (n--)
    {
        int h; cin >> h;
        // 높은 건물에 막히는 애들은 pop()
        while (!s.empty() && s.top() <= h)
            s.pop();
        // stack에 남아있는 건물은 현재 건물을 관찰 가능함
        result += s.size();
        s.push(h);
    }
    cout << result;
}

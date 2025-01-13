// BOG 1158 요세푸스 문제

#include <iostream>
// #include <list>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    queue<int> q;
    int n, k;
    cin >> n >> k;
    for (int i=1; i<=n; ++i)
        q.push(i);
    
    vector<int> result = {};
    // 1 2 3 4 5 6 7
    while (!q.empty())
    {
        for (int i=0; i<k-1; ++i)
        {
            q.push(q.front());
            q.pop();
        }

        result.push_back(q.front());
        q.pop();
    }



    // Sol 1
    
    // list<int> l = {};
    // int n, k;
    // cin >> n >> k;
    // for (int i=1; i<=n; ++i)
    // {
    //     l.push_back(i);
    // }

    // list<int>::iterator it = l.end();
    // --it; // begin()부터 카운팅 하기 위함

    // // 1 2 3 4 5 6 7
    // vector<int> result = {};
    // while (l.size() > 0)    
    // {
    //     for (int i=0; i<k; ++i)
    //     {
    //         ++it;
    //         if (it == l.end())
    //             it = l.begin();
    //     }

    //     result.push_back(*it);
    //     it = l.erase(it);
    //     // 한 칸 앞서기 때문에 it을 한 칸 뒤로 당긴다
    //     --it;
    // }

    int len = result.size();

    // 길이가 1일 때 예외 처리
    if (len == 1)
    {
        cout << "<" << result[0] << ">";
        return 0;
    }
        
    for (int i=0; i<len; ++i)
    {
        if (i == 0)
            cout << '<' << result[i] << ", ";
        else if (i == len - 1)
            cout << result[i] <<'>';
        else
            cout << result[i] << ", ";
    }
}


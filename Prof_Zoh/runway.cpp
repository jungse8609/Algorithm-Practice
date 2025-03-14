#include <iostream>
using namespace std;

int arr[5001][5001];
pair<bool, bool> visited[5001][5001]; // pair<가로, 세로>

int main()
{
    int n, m;
    cin >> m >> n; // n이 열, m이 행

    // input
    for (int i=0; i<m; ++i)
    {
        string line;
        cin >> line;
        for (int j=0; j<n; ++j)
            arr[i][j] = line[j] - '0';
    }

    int result = 0;
    pair<int, int> ord {m + 2, n + 2};

    // 길이가 2이니 여유분 1을 위해 n-1, m-1까지 반복복
    for (int i=0; i<m-1; ++i)
    {
        for (int j=0; j<n-1; ++j)
        {
            int rowLen = 0;
            int colLen = 0;

            // 만약 가로 검사한 left upper면 패스

            if (!visited[i][j].first)
            {
                // row
                for (int x=j; x<n; ++x)
                {
                    // check validation
                    if (arr[i][x] == 0 && arr[i + 1][x] == 0)
                    {
                        // 길로 인정되면 가로 길이 + 1
                        rowLen += 1;

                        // 현재 좌표를 left upper로 탐색했다고 표시
                        visited[i][x].first = true;
                    }
                    else    
                        break;
                }
            }

            // 만약 세로 검사한 left upper면 패스
            if (!visited[i][j].second)
            {
                // column
                for (int y=i; y<m; ++y)
                {
                    // check validation
                    if (arr[y][j] == 0 && arr[y][j + 1] == 0)
                    {
                        // 길로 인정되면 세로 길이 + 1
                        colLen += 1;

                        // 현재 좌표를 left upper로 탐색했다고 표시
                        visited[y][j].second = true;
                    }
                    else    
                        break;
                }
            }

            int curLen = max(rowLen, colLen);
            if (result <= curLen && curLen > 1)
            {
                // 현재 좌표 (j+1, n-i)
                if (result < curLen || ord.first > j + 1 || (ord.first == j + 1 && ord.second > n - i))
                {
                    result = curLen;
                    ord = {j + 1, m - i};
                    // cout << i << ", " << j << " => "
                    //     << "현재 좌표 : (" 
                    //     << ord.first 
                    //     << ", " << ord.second 
                    //     <<"), 최고 길이 : " 
                    //     << result << '\n';
                }
            }
        }
    }

    if (ord.first == n+2 && ord.second == m+2)
        cout << "0 0 0";
    else
        cout << ord.first << ' ' << ord.second << ' ' << result;
}
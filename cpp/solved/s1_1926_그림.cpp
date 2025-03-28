#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m, cnt = 0, area = 0;
vector<vector<int>> adj;
vector<vector<bool>> visited;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void bfs(int x, int y)
{
    queue<pair<int, int>> q;    
    q.push({x, y});

    visited[x][y] = true;

    int curArea = 0;
    curArea += 1;

    while (!q.empty())
    {
        pair<int, int> here = q.front();
        q.pop();
        for (int i=0; i<4; ++i)
        {
            int nx = here.first + dx[i];
            int ny = here.second + dy[i];
            
            if (0 <= nx && nx < n && 0 <= ny && ny < m)
            {
                if (!visited[nx][ny] && adj[nx][ny] == 1)
                {
                    visited[nx][ny] = true;
                    q.push({nx, ny});
                    curArea += 1;
                }
            }
        }
    }

    area = max(area, curArea);
}

void bfsAll()
{
    // N^2
    for (int i=0; i<n; ++i)
        for (int j=0; j<m; ++j)
            if (!visited[i][j] && adj[i][j] == 1)
            {
                cnt += 1;
                bfs(i, j);
            }
                
}

int main()
{
    cin.tie(0); ios::sync_with_stdio(0);

    cin >> n >> m;

    adj = vector<vector<int>>(n, vector<int>(m));
    visited = vector<vector<bool>>(n, vector<bool>(m, false));

    // N^2
    for (auto& line : adj)
        for (auto& e : line)
            cin >> e;

    bfsAll();

    cout << cnt << '\n' << area;
}
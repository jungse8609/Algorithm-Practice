#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m, result = -1;
vector<vector<int>> adj;
vector<vector<bool>> visited;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void bfs(int x, int y)
{
    vector<vector<bool>> discovered(n, vector<bool>(m, false));
    queue<pair<int, int>> q;    
    q.push({x, y});
    result += 1;
    discovered[x][y] = true;

    while (!q.empty())
    {
        pair<int, int> here = q.front();
        q.pop();
        for (int i=0; i<4; ++i)
        {
            int nx = here.first + dx[i];
            int ny = here.second + dy[i];

            if (!discovered[nx][ny] && adj[nx][ny] == 1)
            {
                discovered[nx][ny] = true;
                q.push({nx, ny});
                result += 1;
            }
        }
    }

    for (int i=0; i<n; ++i)
        for (int j=0; j<m; ++j)
            if (discovered[i][j] == 1)
                visited[i][j] = 1;
}

void bfsAll()
{
    for (int i=0; i<n; ++i)
        for (int j=0; j<m; ++j)
            if (!visited[i][j] && adj[i][j] == 1)
                bfs(i, j);
}

int main()
{
    cin.tie(0); ios::sync_with_stdio(0);

    cin >> n >> m;
    adj = vector<vector<int>>(n, vector<int>(m));
    visited = vector<vector<bool>>(n, vector<bool>(m, false));

    for (auto& line : adj)
        for (auto& e : line)
            cin >> e;

    bfsAll();

    cout << result;
}
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <list>
#include <utility>
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
using namespace std;

// 세로 → 행, 가로 → 열

//            0번째 열   1번째 열 → 가로 (m)
// 0번째행 ->      ↓        ↓
// 1번째행 ->
// 2번째행 ->
//  ↓세로(n)

int board[505][505];
int vis[505][505];
int n, m, mx, num; // 6 5
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>n; cin>>m;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> board[i][j];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (board[i][j] == 0 || vis[i][j])
                continue;
            num++;
            queue< pair<int, int> > q;
            vis[i][j] = 1;
            q.push(make_pair(i, j));
            int area = 0;
            while (!q.empty())
            {
                area++;
                pair<int, int> cur = q.front();
                q.pop();
                for (int dir = 0; dir < 4; dir++)
                {
                    int nx = cur.first + dx[dir];
                    int ny = cur.second + dy[dir];
                    if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                        continue;
                    if (vis[nx][ny] || board[nx][ny] != 1)
                        continue;
                    vis[nx][ny] = 1;
                    q.push(make_pair(nx, ny));
                }
            }
            mx = max(mx, area);
        }
    }
    cout << num << '\n' << mx;    
    return 0;
}
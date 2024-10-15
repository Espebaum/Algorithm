#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define int long long
const int INF = 0x3f3f3f3f;
using namespace std;

char    board[101][101];
int vis[101][101];
int     N;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int point;

void    bfs(int w)
{
    queue<pair<int,int>>q;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (!vis[i][j]) {
                point++;
                char p = board[i][j];
                vis[i][j] = 1;
                q.push({i, j});
                while (!q.empty()) {
                    pair<int,int>cur = q.front(); q.pop();
                    for (int dir = 0; dir < 4; dir++) {
                        int nx = cur.first + dx[dir];
                        int ny = cur.second + dy[dir];
                        if (nx < 0 || nx >= N || ny < 0 || ny >= N)
                            continue;
                        if (w == 0) {
                            if (vis[nx][ny] || board[nx][ny] != p)
                                continue;
                        } else {
                            if (p == 'B') {
                                if (vis[nx][ny] || board[nx][ny] != p)
                                    continue ;
                            } else {
                                if (vis[nx][ny] || board[nx][ny] == 'B')
                                    continue ;
                            }
                        }
                        vis[nx][ny] = 1;
                        q.push({nx, ny});
                    }
                }
            }
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cin >> board[i][j];
    }
    bfs(0);
    cout << point << ' '; point = 0;
    for (int i = 0; i < 100; i++)
        for (int j = 0; j < 100; j++)
            vis[i][j] = 0;
    bfs(1);
    cout << point << '\n';
    return 0;
}
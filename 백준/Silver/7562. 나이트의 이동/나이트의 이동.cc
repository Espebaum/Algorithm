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

int tc;
int l;
int dx[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int board[303][303];
int dist[303][303];

void    solve()
{
    int l;
    cin >> l;
    int board[l][l];
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < l; j++) {
            board[i][j] = 0;
            dist[i][j] = -1;
        }
    }

    int kx, ky;
    int cx, cy;
    cin >> kx >> ky;
    cin >> cx >> cy;
    dist[kx][ky] = 0;
    queue< pair<int, int> > q;
    q.push(make_pair(kx, ky));

    while (!q.empty())
    {
        pair<int, int> cur = q.front(); q.pop();
        if (cur.first == cx && cur.second == cy)
            break ;
        for (int dir = 0; dir < 8; dir++)
        {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            if (nx < 0 || nx >= l || ny < 0 || ny >= l)
                continue;
            if (dist[nx][ny] >= 0)
                continue;
            dist[nx][ny] = dist[cur.first][cur.second] + 1;
            q.push(make_pair(nx, ny));
        }
    }
    cout << dist[cx][cy] << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> tc;

    while (tc--)
        solve();

    return 0;
}
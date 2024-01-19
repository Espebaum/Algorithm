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
#include <cmath>
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
typedef long long ll;
using namespace std;

int n, m;
int board[1010][1010];
int dist[1010][1010];
int tx, ty;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
            dist[i][j] = -1;
            if (board[i][j] == 2) {
                tx = i;
                ty = j;
            } else if (board[i][j] == 0)
                dist[i][j] = 0;
        }
    }
    queue< pair<int, int> > q;
    dist[tx][ty] = 0;
    q.push(make_pair(tx, ty));
    while (!q.empty())
    {
        pair<int, int> cur = q.front(); q.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            if (nx < 0 || nx > n || ny < 0 || ny > m)
                continue;
            if (dist[nx][ny] != -1 || dist[nx][ny] == 0)
                continue;
            if (board[nx][ny] == 0) {
                dist[nx][ny] = 0;
                continue;
            }
            dist[nx][ny] = dist[cur.first][cur.second] + 1;
            q.push(make_pair(nx, ny));
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << dist[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}
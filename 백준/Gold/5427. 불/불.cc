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
int n, m;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
string board[1010];
int dist1[1010][1010]; // fire
int dist2[1010][1010]; // sanggeun

void    solve()
{
    cin>> m >> n;

    queue< pair<int, int> > q1; // fire
    queue< pair<int, int> > q2; // sanggeun

    for (int i = 0; i < n; i++)
    {
        cin >> board[i];
        for(int j = 0; j < m; j++)
        {
            dist1[i][j] = -1; dist2[i][j] = -1;
            if (board[i][j] == '*') {
                q1.push(make_pair(i, j));
                dist1[i][j] = 0;
            }
            if (board[i][j] == '@') {
                q2.push(make_pair(i, j));
                dist2[i][j] = 0;
            }
        }
    }

    while (!q1.empty())
    {
        pair<int, int> cur = q1.front(); q1.pop();
        for (int dir = 0; dir < 4; dir++)
        {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;
            if (board[nx][ny] == '#' || dist1[nx][ny] >= 0)
                continue;
            dist1[nx][ny] = dist1[cur.first][cur.second] + 1;
            q1.push(make_pair(nx, ny));
        }
    }

    while (!q2.empty())
    {
        pair<int, int> cur = q2.front(); q2.pop();
        for (int dir = 0; dir < 4; dir++)
        {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
                cout << dist2[cur.first][cur.second] + 1 << '\n';
                return ;
            }
            if (board[nx][ny] == '#' || dist2[nx][ny] >= 0)
                continue;
            if (dist1[nx][ny] != -1 && (dist1[nx][ny] <= dist2[cur.first][cur.second] + 1))
                continue;
            dist2[nx][ny] = dist2[cur.first][cur.second] + 1;
            q2.push(make_pair(nx, ny));   
        }
    }
    cout << "IMPOSSIBLE" << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>tc;

    while (tc--)
        solve();

    return 0;
}
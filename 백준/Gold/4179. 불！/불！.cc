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

int n, m;
string board[1010];
int mov[1010][1010];
int fire[1010][1010];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n; cin >> m;

    for (int i = 0; i < n; i++) {
        cin >> board[i];
    }

    for (int i = 0; i < n; i++)
    {
        fill(fire[i], fire[i] + m, -1);
        fill(mov[i], mov[i] + m, -1);
    }

    queue< pair<int, int> > q1; // fire
    queue< pair<int, int> > q2; // mov

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (board[i][j] == 'F') {
                q1.push(make_pair(i, j));
                fire[i][j] = 0;
            }
            if (board[i][j] == 'J') {
                q2.push(make_pair(i, j));
                mov[i][j] = 0;
            }
        }
    }

    while (!q1.empty()) // 불의 dfs
    {
        pair<int, int> cur = q1.front(); q1.pop();
        for (int dir = 0; dir < 4; dir++)
        {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;
            if (fire[nx][ny] >= 0 || board[nx][ny] == '#')
                continue;
            fire[nx][ny] = fire[cur.first][cur.second] + 1;
            q1.push(make_pair(nx, ny));
        }
    }

    while (!q2.empty()) // j의 dfs
    {
        pair<int, int> cur = q2.front(); q2.pop();
        for (int dir = 0; dir < 4; dir++)
        {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            // cout << nx << ny << ' ' << mov[nx][ny] << ' ' << board[nx][ny] << '\n';
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
                // cout << "nx: " << nx << " ny : " << ny << '\n'; 
                cout << mov[cur.first][cur.second] + 1;
                return 0; 
            }
            if (mov[nx][ny] >= 0 || board[nx][ny] == '#')
                continue;
            if (fire[nx][ny] != -1 && fire[nx][ny] <= mov[cur.first][cur.second] + 1)
                continue;
            mov[nx][ny] = mov[cur.first][cur.second] + 1;
            q2.push(make_pair(nx, ny));
        }
    }
    cout << "IMPOSSIBLE";
    return 0;
}
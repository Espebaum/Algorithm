#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
// #define int long long
const int INF = 0x3ff3f3f;
using namespace std;

int tc;
int w, h;
char board[1010][1010];
int fire[1010][1010];
int dog[1010][1010];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int flag;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> tc;

    while (tc--)
    {
        flag = 0;
        queue<pair<int,int>>f;
        queue<pair<int,int>>s;
        cin >> w >> h;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                fire[i][j] = -1;
                dog[i][j] = -1;
            }
        }
        int sx, sy;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                cin >> board[i][j];
                if (board[i][j] == '@') {
                    s.push({i, j});
                    dog[i][j] = 0;
                } else if (board[i][j] == '*') {
                    f.push({i, j});
                    fire[i][j] = 0;
                }
            }
        }
        while (!f.empty())
        {
            pair<int,int>cur = f.front(); f.pop();
            for (int dir = 0; dir < 4; dir++)
            {
                int nx = cur.first + dx[dir];
                int ny = cur.second + dy[dir];
                if (nx < 0 || nx >= h || ny < 0 || ny >= w)
                    continue ;
                if (board[nx][ny] == '#' || fire[nx][ny] >= 0)
                    continue;
                fire[nx][ny] = fire[cur.first][cur.second] + 1;
                f.push({nx, ny});
            }
        }
        while (!s.empty())
        {
            pair<int,int>cur = s.front(); s.pop();
            if (cur.first == h - 1 || cur.second == w - 1 || cur.first == 0 || cur.second == 0) {
                flag = 1;
                cout << dog[cur.first][cur.second] + 1 << '\n';
                break ;
            }
            for (int dir = 0; dir < 4; dir++)
            {
                int nx = cur.first + dx[dir];
                int ny = cur.second + dy[dir];
                if (nx < 0 || nx >= h || ny < 0 || ny >= w)
                    continue ;
                if (board[nx][ny] == '#' 
                    || (fire[nx][ny] != -1 && fire[nx][ny] <= dog[cur.first][cur.second] + 1) 
                        || dog[nx][ny] != -1)
                    continue ;
                dog[nx][ny] = dog[cur.first][cur.second] + 1;
                s.push({nx, ny});
            }
        }
        if (!flag)
            cout << "IMPOSSIBLE\n";
    }

    return 0;
}
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

int L, R, C;
int dx[6] = {0, 0, 1, -1, 0, 0};
int dy[6] = {1, -1, 0, 0, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    while (1)
    {
        cin >> L >> R >> C;

        if (L == 0 && R == 0 && C == 0)
            break;

        queue<pair<int, pair<int, int> > > q;
        char board[33][33][33];
        int dist[33][33][33];
        
        for (int j = 0; j < R; j++)
            for (int k = 0; k < C; k++)
                fill(dist[j][k], dist[j][k] + L, 0);

        for (int i = 0; i < L; i++)
        {
            for (int j = 0; j < R; j++)
            {
                for (int k = 0; k < C; k++)
                {
                    cin >> board[j][k][i];
                    if (board[j][k][i] == 'S') {
                        q.push(make_pair(j, make_pair(k, i)));
                        dist[j][k][i] = 0;
                    }
                }
            }
        }

        bool isEscape = false;
        while (!q.empty())
        {
            if (isEscape)
                break;
            pair<int, pair<int, int> > cur = q.front(); q.pop();
            int curX, curY, curZ;
            curX = cur.first;
            curY = cur.second.first;
            curZ = cur.second.second;
            for (int dir = 0; dir < 6; dir++)
            {
                int nx = curX + dx[dir];
                int ny = curY + dy[dir];
                int nz = curZ + dz[dir];
                if (nx < 0 || nx >= R || ny < 0 || ny >= C || nz < 0 || nz >= L) 
                    continue;
                if (board[nx][ny][nz] == '#' ||
                dist[nx][ny][nz] > 0)
                    continue;
                dist[nx][ny][nz] = dist[curX][curY][curZ] + 1;
                if (board[nx][ny][nz] == 'E')
                {
                    cout << "Escaped in " << dist[nx][ny][nz] << " minute(s).\n";
                    isEscape = true;
                    break;
                }
                q.push(make_pair(nx, make_pair(ny, nz)));
            }  
        }
        if (!isEscape)
            cout << "Trapped!\n";
    }
    return 0;
}
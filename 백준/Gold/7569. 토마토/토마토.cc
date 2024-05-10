#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
using namespace std;

int M, N, H; // M 가로길이, N 세로길이, H 상자높이
int dx[6] = {0, 0, 1, -1, 0, 0};
int dy[6] = {1, -1, 0, 0, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};
int board[103][103][103];
int dist[103][103][103];
queue<tuple<int,int,int>> q;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> M >> N >> H;

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < M; k++) {
                int tmp; cin >> tmp;
                board[j][k][i] = tmp;
                if (tmp == 1) q.push({j, k, i});
                if (tmp == 0) dist[j][k][i] = -1;
            }
        }
    }

    while (!q.empty())
    {
        tuple<int,int,int>cur = q.front(); q.pop();
        int curX, curY, curZ;
        curX = get<0>(cur);
        curY = get<1>(cur);
        curZ = get<2>(cur);
        for (int dir = 0; dir < 6; dir++)
        {
            int nx = curX + dx[dir];
            int ny = curY + dy[dir];
            int nz = curZ + dz[dir];
            if (nx < 0 || nx >= N || ny < 0 || ny >= M || nz < 0 || nz >= H) 
                continue;
            if (dist[nx][ny][nz] >= 0) continue;
            dist[nx][ny][nz] = dist[curX][curY][curZ] + 1;
            q.push({nx,ny,nz});
        }
    }

    int ans = 0;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < M; k++) {
                if (dist[j][k][i] == -1) {
                    cout << -1 << '\n'; return 0;
                }
                ans = max(ans, dist[j][k][i]);
            }
        }
    }
    cout << ans << '\n';
    return 0;
}
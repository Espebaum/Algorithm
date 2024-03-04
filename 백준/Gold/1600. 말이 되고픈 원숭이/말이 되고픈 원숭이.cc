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
#include <tuple>
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
typedef long long ll;
const int INF = 0x3f3f3f3f;
using namespace std;

int K, W, H;
int board[220][220];
int dist[220][220][31];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int dhx[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dhy[8] = {1, 2, 2, 1, -1, -2, -2, -1}; 

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>K>>H>>W;
    for (int i = 0; i < W; i++) {
        for (int j = 0; j < H; j++)
            cin >> board[i][j];
    }
    int hp = K; // Horse Point kk
    for (int i = 0; i < W; i++)
        for (int j = 0; j < H; j++)
            for (int k = 0; k <= K; k++)
                dist[i][j][k] = -1;

    queue<tuple<int,int,int>> q;
    q.push({0,0,hp});
    dist[0][0][hp] = 0;
    while (!q.empty())
    {
        auto cur = q.front(); q.pop();
        int cx = get<0>(cur); int cy = get<1>(cur);
        int ch = get<2>(cur);
        if (cx == W-1 && cy == H-1) {
            cout << dist[cx][cy][ch]; return 0;
        }
        for (int dir = 0; dir < 4; dir++) {
            int nx = cx + dx[dir];
            int ny = cy + dy[dir];
            if (nx < 0 || nx >= W || ny < 0 || ny >= H)
                continue;
            if (dist[nx][ny][ch] != -1 || board[nx][ny])
                continue;
            dist[nx][ny][ch] = dist[cx][cy][ch] + 1;
            q.push({nx,ny,ch});
        }
        if (ch > 0) {
            for (int dir = 0; dir < 8; dir++) {
                int nx = cx + dhx[dir];
                int ny = cy + dhy[dir];
                if (nx < 0 || nx >= W || ny < 0 || ny >= H)
                    continue;
                if (dist[nx][ny][ch] != -1 || dist[nx][ny][ch - 1] != -1 || board[nx][ny])
                    continue;
                dist[nx][ny][ch - 1] = dist[cx][cy][ch] + 1;
                q.push({nx,ny,ch-1});
            }
        }
    }   
    cout << -1;
    return 0;
}
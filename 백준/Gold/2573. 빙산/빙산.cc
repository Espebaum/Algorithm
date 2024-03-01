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

int N, M;
int board[303][303];
int vis[303][303];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); std::cout.tie(NULL);
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
        }
    }
    int turn = 0;
    while (1)
    {
        vector<tuple<int,int,int>>vt;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (board[i][j]) {
                    int cx = i; int cy = j; int point = 0;
                    for (int dir = 0; dir < 4; dir++) {
                        int nx = cx + dx[dir];
                        int ny = cy + dy[dir];
                        if (nx < 0 || nx >= N || ny < 0 || ny >= M)
                            continue;
                        if (board[nx][ny] == 0)
                            point++;
                    }
                    vt.push_back({i, j, point});
                }
            }
        }
        if (vt.empty()) {
            cout << 0; return 0;
        }
        for (int i = 0; i < vt.size(); i++) {
            int cx = get<0>(vt[i]);
            int cy = get<1>(vt[i]);
            int point = get<2>(vt[i]);
            board[cx][cy] -= point;
            if (board[cx][cy] < 0)
                board[cx][cy] = 0;
        }
        turn++;

        int piece = 0;
        queue<pair<int,int>>q;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (board[i][j] && !vis[i][j]) {
                    piece += 1;
                    if (piece >= 2) {
                        cout << turn; return 0;
                    }
                    q.push({i, j});
                    vis[i][j] = 1;
                    while (!q.empty()) {
                        pair<int,int>cur = q.front(); q.pop();
                        int cx = cur.first; int cy = cur.second;
                        for (int dir = 0; dir < 4; dir++) {
                            int nx = cx + dir[dx];
                            int ny = cy + dir[dy];
                            if (nx < 0 || nx >= N || ny < 0 || ny >= M)
                                continue ;
                            if (!board[nx][ny] || vis[nx][ny])
                                continue ;
                            vis[nx][ny] = 1;
                            q.push({nx, ny});
                        }
                    }
                }
            }
        }
        for (int i = 0; i < N; i++)
            fill(vis[i], vis[i]+M, 0);
    }
    cout << turn;
    return 0;
}

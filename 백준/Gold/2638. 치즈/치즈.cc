#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
const int INF = 0x3f3f3f3f;
using namespace std;

int N, M;
int board[110][110];
int vis[110][110];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void    edge()
{
    queue<pair<int,int>>q;
    q.push({0,0});
    vis[0][0] = 1;
    board[0][0] = -1;
    while (!q.empty())
    {
        pair<int,int>cur=q.front();q.pop();
        int cx = cur.first; int cy = cur.second;
        for (int dir = 0; dir < 4; dir++) {
            int nx = cx + dx[dir];
            int ny = cy + dy[dir];
            if (nx < 0 || nx >= N || ny < 0 || ny >= M)
                continue;
            if (board[nx][ny] != 0 || vis[nx][ny])
                continue;
            board[nx][ny] = -1;
            q.push({nx, ny});
        }
    }
}

void    rid()
{
    int rp = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (board[i][j] == 1) {
                rp = 0;
                int cx = i; int cy = j;
                for (int dir = 0; dir < 4; dir++) {
                    int nx = cx + dx[dir];
                    int ny = cy + dy[dir];
                    if (board[nx][ny] == -1)
                        rp += 1;
                }
                if (rp >= 2)
                    board[i][j] = 0;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>N>>M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++)
            cin>>board[i][j];
    }
    int sec = 0;
    int check;

    while (1)
    {
        check = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (board[i][j] == 1) {
                    check = 1;
                }
            }
        }
        if (!check) {
            cout << sec; return 0;
        }
        edge();
        rid();
        for (int i = 0; i < 110; i++)
            fill(vis[i], vis[i]+110, 0);
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (board[i][j] != 1)
                    board[i][j] = 0;
            }
        }
        sec += 1;
    }
    return 0;
}
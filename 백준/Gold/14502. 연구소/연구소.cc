#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <deque>
#include <utility>
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
using namespace std;

int N, M;
int board[10][10];
vector<pair<int,int>>vp;
int isused[70];
int arr[70];
int mx = -1;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int vis[10][10];

int virus()
{
    int temp[10][10];
    for (int i = 0; i < 10; i++)
        fill(temp[i], temp[i]+10, 0);
        
    int ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            temp[i][j] = board[i][j];
        }
    }

    queue<pair<int,int>> tq;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (board[i][j] == 2 && vis[i][j] == 0) {
                vis[i][j] = 1;
                tq.push({i, j});
                while(!tq.empty())
                {
                    pair<int,int>cur = tq.front(); tq.pop();
                    int cx = cur.first; int cy = cur.second;
                    for (int dir = 0; dir < 4; dir++) {
                        int nx = cx + dx[dir];
                        int ny = cy + dy[dir];
                        if (nx < 0 || nx >= N || ny < 0 || ny >= M)
                            continue;
                        if (vis[nx][ny] == 1 || board[nx][ny] != 0)
                            continue;
                        board[nx][ny] = 2;
                        vis[nx][ny] = 1;
                        tq.push({nx, ny});
                    }
                }
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++)
            if (board[i][j] == 0)
                ans += 1;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            board[i][j] = temp[i][j];
        }
    }
    return ans;
}

void    solve(int k)
{
    if (k == 3) {
        for (int i = 0; i < 10; i++)
            fill(vis[i], vis[i]+10, 0);
        for (int i = 0; i < 3; i++)
            board[vp[arr[i]].first][vp[arr[i]].second] = 1;
        int ans = virus();
        mx = max(mx, ans);
        for (int i = 0; i < 3; i++)
            board[vp[arr[i]].first][vp[arr[i]].second] = 0;
        return ;
    }

    for (int i = 0; i < vp.size(); i++) {
        if (!isused[i]) {
            arr[k] = i;
            isused[i] = 1;
            solve(k + 1);
            isused[i] = 0;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>N>>M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
            if (board[i][j] == 0) {
                vp.push_back({i,j});
            }
        }
    }
    solve(0);
    cout << mx;
    return 0;
}
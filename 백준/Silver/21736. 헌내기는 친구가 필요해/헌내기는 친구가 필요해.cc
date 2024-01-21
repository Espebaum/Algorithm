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

int N, M;
string  board[606];
int vis[606][606];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    int cx, cy;

    for (int i = 0; i < N; i++) {
        cin >> board[i];
        for (int j = 0; j < M; j++) {
            if (board[i][j] == 'I') {
                cx = i; cy = j;
            }
        }
    }

    int ans = 0;
    queue< pair<int, int> > q;
    q.push(make_pair(cx, cy));
    vis[cx][cy] = 1;

    while (!q.empty())
    {
        pair<int, int> cur = q.front(); 
        q.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            if (nx < 0 || nx >= N || ny < 0 || ny >= M)
                continue;
            if (board[nx][ny] == 'X' || vis[nx][ny]) {
                continue;
            }
            vis[nx][ny] = 1;
            if (board[nx][ny] == 'P') {
                ans++;
            }
            q.push(make_pair(nx, ny));
        }
    }
    if (ans == 0) {
        cout << "TT"; return 0;
    }
    cout << ans;
    return 0;
}
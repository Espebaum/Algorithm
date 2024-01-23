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

int N;
int board[101][101];
int vis[101][101];
int ans[101][101];

void    bfs(int k)
{
    int first = k;
    queue<int> q;
    q.push(k);

    while (!q.empty()) {
        int cur = q.front(); q.pop();
        for (int i = 1; i <= N; i++) {
            if (board[cur][i] == 1 && !vis[cur][i]) {
                ans[first][i] = 1;
                vis[cur][i] = 1;
                q.push(i);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> board[i][j];
        }
    }

    for (int i = 1; i <= N; i++) {
        bfs(i);
        for (int j = 1; j <= N; j++) {
            for (int k = 1; k <= N; k++) {
                vis[j][k] = 0;
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cout << ans[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}
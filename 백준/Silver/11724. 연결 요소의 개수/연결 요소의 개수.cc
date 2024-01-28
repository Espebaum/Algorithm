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
using namespace std;

int N, M;
int board[1010][1010];
int vis[1010];

void    dfs(int k)
{
    vis[k] = 1;
    for (int i = 1; i <= N; i++) {
        if (!vis[i] && board[k][i]) {
            dfs(i);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;

    for (int i = 0; i < M; i++)
    {
        int x, y; cin >> x >> y;
        board[x][y] = 1;
        board[y][x] = 1;
    }

    int cnt = 0;
    for (int i = 1; i <= N; i++) {
        if (!vis[i]) {
            dfs(i);
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}
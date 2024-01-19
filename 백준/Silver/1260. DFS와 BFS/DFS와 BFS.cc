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

int N, M, V;
int board[1010][1010];
int vis[1010];
int vis2[1010];

void    dfs(int v)
{
    vis[v] = 1;
    cout << v << ' ';

    for (int i = 1; i <= N; i++)
    {
        if (board[v][i] == 1 && !vis[i])
            dfs(i);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M >> V;
    
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            int x, y; cin >> x >> y;
            board[x][y] = 1;
            board[y][x] = 1;
        }
    }

    dfs(V);
    cout << '\n';

    queue<int> q;
    vis2[V] = 1;
    q.push(V);

    while (!q.empty())
    {
        int cur = q.front(); q.pop();
        cout << cur << ' ';
        for (int i = 0; i <= N; i++) {
            if (board[cur][i] == 1 && !vis2[i]) {
                vis2[i] = 1;
                q.push(i);
            }   
        }
    }

    return 0;
}
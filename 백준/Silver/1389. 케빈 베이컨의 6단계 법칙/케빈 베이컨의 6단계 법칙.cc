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
int board[101][101];
int vis[101];
int ans[101][101];

bool    compare(pair<int, int> a, pair<int, int> b)
{
    if (a.second == b.second)
        return a.first < b.first;
    else
        return a.second < b.second;
}

void    bfs(int k)
{
    int now = k;
    int check = 0;
    queue<int> q;
    q.push(k);
    
    vis[k] = 1;
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        for (int i = 1; i <= N; i++) {
            if (i == 1)
                check++;
            if (!vis[i] && board[cur][i]) {
                ans[now][i] = ans[now][cur] + 1;
                vis[i] = 1;
                q.push(i);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;

    for (int i = 1; i <= M; i++) {
        int x, y; 
        cin >> x >> y;
        board[x][y] = 1;
        board[y][x] = 1;
    }

    for (int i = 1; i <= N; i++) {
        bfs(i);
        for (int i = 1; i <= N; i++)
            vis[i] = 0;
    }

    vector< pair<int, int> > res;
    for (int i = 1; i <= N; i++) {
        int sum = 0;
        for (int j = 1; j <= N; j++) {
            sum += ans[i][j];
        }
        res.push_back(make_pair(i, sum));
    }
    sort(res.begin(), res.end(), compare);
    cout << res[0].first << '\n';

    return 0;
}
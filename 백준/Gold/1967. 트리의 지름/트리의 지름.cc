#include <algorithm>
#include <iostream>
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

int N;
long long node, ans;
vector<pair<int,int>> adj[10010];
bool    vis[10010];

void    dfs(int k, int dist)
{
    if (vis[k])
        return ;

    vis[k] = 1;

    if (dist > ans) {
        ans = dist;
        node = k;
    }

    for (int i = 0; i < adj[k].size(); i++)
        dfs(adj[k][i].first, dist + adj[k][i].second);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;

    if (N == 1) {
        cout << 0; return 0;
    }

    for (int i = 0; i < N; i++) {
        int p, c, w; cin>>p>>c>>w;
        adj[p].push_back({c, w});
        adj[c].push_back({p, w});
    }

    dfs(1, 0);
    ans = 0;
    for (int i = 0; i <= 10001; i++) 
        vis[i] = 0;
    dfs(node, 0);
    cout << ans;
    return 0;
}
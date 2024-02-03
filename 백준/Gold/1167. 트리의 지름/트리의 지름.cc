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

int V;
vector<pair<int,int>>adj[100010];
int vis[100010];
int ans, node;

void    dfs(int k, int dist)
{
    if (vis[k])
        return ;

    vis[k] = 1;

    if (dist > ans)
    {
         ans = dist;
         node = k;
    }

    for (int i = 0; i < adj[k].size(); i++)
        dfs(adj[k][i].first, dist+adj[k][i].second);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> V;

    if (V == 1) {
        cout << 0; return 0;
    }

    for (int i = 0; i < V; i++) {
        int node; cin >> node;
        while (1) {
            int c; cin>>c;
            if (c == -1)
                break ;
            int w; cin>>w;
            adj[node].push_back({c, w});
            adj[c].push_back({node, w});
        }
    }
    dfs(1, 0);
    ans = 0;
    for (int i = 0; i <= 100010; i++) 
        vis[i] = 0;
    // cout << "node : " << node << '\n';
    dfs(node, 0);
    cout << ans;
    return 0;
}
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
const int INF = 0x3f3f3f3f;
using namespace std;

int V, E;
int A, B, C;
// vector<pair<int,int>>adj[10101];
vector<tuple<int,int,int>>adj;
int par[10101];

int Find(int x)
{
    if (par[x] == x) return x;
    return par[x] = Find(par[x]);
}

void    Union(int x, int y)
{
    int px = Find(x);
    int py = Find(y);
    par[px] = py;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>V>>E;
    for (int i = 0; i < V; i++) {
        par[i] = i;
    }
    for (int i = 0; i < E; i++) {
        int p,c,w;cin>>p>>c>>w;
        adj.push_back({w, p, c});
    }
    sort(adj.begin(), adj.end());

    int ans = 0;

    for (int i = 0; i < E; i++) {
        int nw = get<0>(adj[i]);
        int nx = get<1>(adj[i]);
        int ny = get<2>(adj[i]);
        if (Find(nx) == Find(ny))
            continue;
        Union(nx, ny);
        ans += nw;
    }
    cout << ans;
    return 0;
}
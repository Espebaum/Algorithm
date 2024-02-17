#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <deque>
#include <utility>
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
const int INF = 0x3f3f3f3f;
using namespace std;

int n, m, r;
int node[110];
vector<pair<int,int>>adj[110];
int ans = 0;
int res[110];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>n>>m>>r;
    for (int i = 1; i <= n; i++) {
        cin >> node[i];
    }
    for (int i = 1; i <= r; i++) {
        int p, c, w; cin>>p>>c>>w;
        adj[p].push_back({w, c});
        adj[c].push_back({w, p});
    }

    for (int i = 1; i <= n; i++) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        int d[110];
        fill(d, d+110, INF);
        d[i] = 0;
        pq.push({d[i], i});
        while (!pq.empty())
        {
            pair<int,int>cur=pq.top();pq.pop();
            // cur.first => d, cur.second => node
            if (d[cur.second] != cur.first)
                continue;
            for (int j = 0; j < adj[cur.second].size(); j++) {
                pair<int,int>nxt=adj[cur.second][j];
                if (d[nxt.second] > cur.first+nxt.first) {
                    d[nxt.second] = cur.first+nxt.first;
                    pq.push({d[nxt.second], nxt.second});
                }
            }
        }
        for (int i = 1; i <= n; i++) {
            if (d[i] <= m)
                ans += node[i];
        }
        res[i] = ans;
        ans = 0;
    }
    cout << *max_element(res+1, res+n+1);
    return 0;
}
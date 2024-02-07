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

int N, E;
vector<pair<int,int>>adj[808];
int a, b, c;
int d[808];
int d1[808];
int d2[808];
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> E;
    for (int i = 0; i < E; i++) {
        cin>>a>>b>>c;
        adj[a].push_back({c, b});
        adj[b].push_back({c, a});
    }
    int p1, p2;
    cin >> p1 >> p2;
    
    fill(d, d+808, INF);
    d[1] = 0;
    pq.push({d[1], 1});
    while (!pq.empty())
    {
        pair<int,int>cur = pq.top(); pq.pop();
        // cur.first => dist, cur.second =>node
        if (d[cur.second] != cur.first)
            continue;
        for (int i = 0; i < adj[cur.second].size(); i++) {
            pair<int,int>nxt = adj[cur.second][i];
            if (d[nxt.second] > cur.first + nxt.first) {
                d[nxt.second] = cur.first + nxt.first;
                pq.push({d[nxt.second], nxt.second});
            }
        }
    }
    
    fill(d1, d1+808, INF);
    d1[p1] = 0;
    pq.push({d1[p1], p1});
    while (!pq.empty())
    {
        pair<int,int>cur = pq.top(); pq.pop();
        // cur.first => dist, cur.second =>node
        if (d1[cur.second] != cur.first)
            continue;
        for (int i = 0; i < adj[cur.second].size(); i++) {
            pair<int,int>nxt = adj[cur.second][i];
            if (d1[nxt.second] > cur.first + nxt.first) {
                d1[nxt.second] = cur.first + nxt.first;
                pq.push({d1[nxt.second], nxt.second});
            }
        }
    }

    fill(d2, d2+808, INF);
    d2[p2] = 0;
    pq.push({d2[p2], p2});
    while (!pq.empty())
    {
        pair<int,int>cur = pq.top(); pq.pop();
        // cur.first => dist, cur.second =>node
        if (d2[cur.second] != cur.first)
            continue;
        for (int i = 0; i < adj[cur.second].size(); i++) {
            pair<int,int>nxt = adj[cur.second][i];
            if (d2[nxt.second] > cur.first + nxt.first) {
                d2[nxt.second] = cur.first + nxt.first;
                pq.push({d2[nxt.second], nxt.second});
            }
        }
    }
    int result1 = (d[p1] == INF || d1[p2] == INF || d2[N] == INF) ? INF : d[p1] + d1[p2] + d2[N];
    int result2 = (d[p2] == INF || d2[p1] == INF || d1[N] == INF) ? INF : d[p2] + d2[p1] + d1[N];

    if (result1 == INF && result2 == INF) {
        cout << "-1\n";
    } else {
        cout << min(result1, result2) << '\n';
    }
    return 0;
}
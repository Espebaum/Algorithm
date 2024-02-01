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

int N, M, W;
int dist[505];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int TC;
    cin >> TC;

    while (TC--) {
        cin >> N >> M >> W;
        vector<pair<int,int>> adj[505];
        for (int i = 0; i < M; i++) {
            int S,E,T; cin>>S>>E>>T;
            adj[S].push_back({E, T});
            adj[E].push_back({S, T});
        }
        for (int i = 0; i < W; i++) {
            int S,E,T; cin>>S>>E>>T;
            adj[S].push_back({E,-T});
        }
        bool nc = false;
        dist[1] = 0;
        // 모든 정점의 개수만큼
        for (int k = 0; k < N; k++) {
            // 모든 정점에 대하여
            for (int i = 1; i <= N; i++) {
                // 정점의 연결부에 대하여
                for (int j = 0; j < adj[i].size(); j++) {
                    int dst = adj[i][j].first;
                    int w = adj[i][j].second;
                    if (dist[dst] > dist[i] + w) {
                        dist[dst] = dist[i] + w;
                        if (k == N - 1)
                            nc = true ;
                    }
                }
            }
        }
        if (nc)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}
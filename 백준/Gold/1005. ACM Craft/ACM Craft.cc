#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
const int INF = 0x3f3f3f3f;
using namespace std;

int T;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> T;

    while (T--)
    {
        int N, K, W;
        vector<int> D(1010, 0); // 건설시간
        vector<int> adj[1010]; // 연결된 노드
        vector<int> degree(1005, 0); // 루트로부터 몇번째
        vector<int> sum(1005, 0); // 현재노드까지 건설시간
        queue<int>q;
        cin >> N >> K;
        for (int i = 1; i <= N; i++) {
            cin >> D[i];
            sum[i] = D[i];
        }
        for (int i = 0; i < K; i++) {
            int x, y;
            cin >> x >> y;
            adj[x].push_back(y);
            degree[y]++;
        }
        cin >> W;
        for (int i = 1; i <= N; i++) {
            if (!degree[i]) {
                q.push(i); // 시작점
            }
        }
        int top, next;
        while (!q.empty())
        {
            top = q.front();
            q.pop();
            for (int i = 0; i < adj[top].size(); i++) {
                next = adj[top][i];
                if (sum[top]+D[next] > sum[next])
                    sum[next] = sum[top]+D[next];
                degree[next]--;
                if (!degree[next])
                    q.push(next);
            }
        }
        cout << sum[W] << '\n';
    }
    return 0;
}
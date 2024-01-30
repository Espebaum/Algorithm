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

int ans[102][102];
int nxt[102][102];
bool vis[102];
int n, m;

void    Floyd()
{
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                if (ans[j][k] > ans[j][i] + ans[i][k]) {
                    ans[j][k] = ans[j][i] + ans[i][k];
                    nxt[j][k] = nxt[j][i]; 
                }
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            if (i != j)
                ans[i][j] = INF;
    }

    for (int i = 0; i < m; i++) {
        int p, c, m; cin>>p>>c>>m;
        ans[p][c] = min(m, ans[p][c]);
        nxt[p][c] = c;
    }

    Floyd();

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (ans[i][j] == INF) 
                cout << 0 << ' ';
            else
                cout << ans[i][j] << ' ';
        }
        cout << '\n';
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j || ans[i][j] == INF) {
                cout << 0 << '\n';
                continue ;
            }
            vector<int> path;
            int st = i;
            while (st != j) {
                path.push_back(st);
                st = nxt[st][j];
            }
            path.push_back(j);
            cout << path.size() << ' ';
            for (int i = 0; i < path.size(); i++)
                cout << path[i] << ' ';
            cout << '\n';
        }
    }

    return 0;
}
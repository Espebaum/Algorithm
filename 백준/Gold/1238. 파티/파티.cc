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

int N, M, X;
int ans[1010][1010];
vector<int> dist;

void    Floyd()
{
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            for (int k = 1; k <= N; k++) {
                if (ans[j][k] > ans[j][i] + ans[i][k])
                    ans[j][k] = ans[j][i] + ans[i][k];
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>N>>M>>X;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (i != j)
                ans[i][j] = INF;
        }
    }

    for (int i = 0; i < M; i++) {
        int p,c,l; cin>>p>>c>>l;
        ans[p][c] = min(ans[p][c], l);
    }

    Floyd();

    int mx = -1;
    for (int i = 1; i <= N; i++) {
        if (i == X)
            continue ;
        for (int j = 1; j <= N; j++) {
            if (j == X) {
                ans[i][X] += ans[X][i];
                mx = max(mx, ans[i][X]);
            }
       }
    }
    cout << mx;

    return 0;
}
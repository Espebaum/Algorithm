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
using namespace std;

int N, K;
int dp[102][100001];
int w[102];
int v[102];

void    solve()
{
    for (int lim = 1; lim <= K; lim++) {
        for (int row = 1; row <= N; row++) {
            if (w[row] > lim)
                dp[row][lim] = dp[row - 1][lim];
            else
                dp[row][lim] = max(dp[row - 1][lim - w[row]] + v[row], dp[row - 1][lim]);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> K;

    for (int i = 1; i <= N; i++) {
        cin >> w[i] >> v[i];
    }

    solve();

    cout << dp[N][K];

    return 0;
}
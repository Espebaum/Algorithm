#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
const int INF = 0x3f3f3f3f;
using namespace std;

int N, K;
int w[110];
int v[110];
int dp[110][100010];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> K;
    for (int i = 1; i <= N; i++) {
        cin >> w[i] >> v[i];
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= K; j++) {
            if (w[i] <= j)
                dp[i][j] = max(dp[i - 1][j - w[i]] + v[i], dp[i - 1][j]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    cout << dp[N][K];
    return 0;
}
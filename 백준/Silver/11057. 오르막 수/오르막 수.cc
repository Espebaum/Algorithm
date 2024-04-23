#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
const int INF = 0x3f3f3f3f;
using namespace std;
typedef long long ll;

int N;
ll dp[1010][15];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;

    ll sum = 0;
    for (int i = 1; i <= 10; i++) {
        dp[1][i] = 1;
        sum += dp[1][i];
    }
    dp[1][11] = sum;

    sum = 0;
    for (int i = 1; i <= 10; i++) {
        dp[2][i] = i;
        sum += dp[2][i];
    }
    dp[2][11] = sum;

    for (int i = 3; i <= N; i++) {
        sum = 0;
        for (int j = 1; j <= 10; j++) {
            if (j == 1)
                dp[i][j] = 1;
            else
                dp[i][j] = (dp[i][j - 1] + dp[i - 1][j]) % 10007;
            sum += dp[i][j];
            sum %= 10007;
        }
        dp[i][11] = sum % 10007;
    }

    cout << dp[N][11];

    return 0;
}
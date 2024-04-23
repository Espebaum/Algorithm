#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
const int INF = 0x3f3f3f3f;
using namespace std;

int N;
int dp[1010101];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3; // 1+2
    for (int i = 3; i <= N; i++)
        dp[i] = (dp[i - 2] + dp[i - 1]) % 15746;
    cout << dp[N] % 15746;

    return 0;
}
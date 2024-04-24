#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
const int INF = 0x3f3f3f3f;
using namespace std;

int T;
int N;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> T;
    for (int i = 0; i < T; i++)
    {
        cin >> N;
        vector<int>coins(N);
        int dp[10101];
        fill(dp, dp+10101, 0);
        int target;
        dp[0] = 1;
        for (int i = 0; i < N; i++)
            cin >> coins[i];
        cin >> target;

        for (int i = 0; i < coins.size(); i++) {
            for (int j = coins[i]; j <= target; j++)
                dp[j] += dp[j - coins[i]];
        }
        cout << dp[target] << '\n';
    }

    return 0;
}
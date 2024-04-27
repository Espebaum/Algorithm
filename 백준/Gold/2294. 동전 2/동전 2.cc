#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
const int INF = 0x3f3f3f3f;
using namespace std;

int n, k;
int arr[110];
int dp[10010];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> arr[i];

    sort(arr+1, arr+n);
    fill(dp, dp+10010, INF);
    dp[0] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = arr[i]; j <= k; j++) {
            dp[j] = min({dp[j], dp[j - arr[i]] + 1});
        }
    }

    if (dp[k] == INF)
        cout << -1;
    else
        cout << dp[k];
        
    return 0;
}
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
const int INF = 0x3f3f3f3f;
using namespace std;

int N;
int arr[10101];
int dp[10101];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;

    for (int i = 1; i <= N; i++)
        cin >> arr[i];

    dp[1] = arr[1];
        
    int mx = -1;
    for (int i = 2; i <= N; i++) {
        for (int j = 1; j < i; j++) {
            // cout << dp[i - j] + arr[j] << '\n';
            // cout << arr[i] << '\n';
            mx = max({dp[i - j] + arr[j], arr[i], mx});
        }
        dp[i] = mx;
    }

    // for (int i = 1; i <= N; i++)
    //     cout << dp[i] << ' ';
    // cout << '\n';

    cout << dp[N];
    return 0;
}

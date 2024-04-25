#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
const int INF = 0x3f3f3f3f;
using namespace std;

int N;
int a[5010], dp[5010];
int mod = 1000000;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    string s; cin >> s;
    N = s.length();
    s = "0" + s;

    for (int i = 1; i <= N; i++)
        a[i] = s[i] - '0';

    dp[0] = 1;

    for (int i = 1; i <= N; i++) {
        if (a[i] > 0) 
            dp[i] = (dp[i] + dp[i - 1]) % mod;
        int x = a[i - 1] * 10 + a[i];
        if (x >= 10 && x <= 26)
            dp[i] = (dp[i] + dp[i - 2]) % mod;
    
    }
    cout << dp[N];
    return 0;
}
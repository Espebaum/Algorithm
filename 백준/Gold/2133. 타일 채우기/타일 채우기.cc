#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
const int INF = 0x3f3f3f3f;
using namespace std;
typedef long long ll;

int N;
ll dp[33];

int check(int k)
{
    ll sum = 0;
    ll st = k - 2;
    for (int i = st; i >= 0; i -= 2) 
    {
        if (i == st)
            sum += dp[i] * 3;
        else
            sum += dp[i] * 2;
    }
    sum += 2;
    return sum;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;

    dp[1] = 0;
    dp[2] = 3;
    dp[3] = 0;
    dp[4] = 11;

    for (int i = 5; i <= N; i++) {
        int half = i/2;
        if (i % 2)
            dp[i] = 0;
        else
            dp[i] = check(i);
    }
    cout << dp[N];
    return 0;
}
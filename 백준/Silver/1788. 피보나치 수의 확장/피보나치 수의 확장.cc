#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
const int INF = 0x3f3f3f3f;
using namespace std;

int n;
int dp[1010101];
int mdp[1010101];

void    solve()
{
    // f(1) = 1, f(0) = 0;
    // f(1) = f(0) + f(-1)  -> f(-1) = 1
    // f(0) = f(-1) + f(-2) -> f(-2) = -1
    // f(-1) = f(-2) + f(-3) -> f(-3) = 2
    // f(-2) = f(-3) + f(-4) -> f(-4) = -3
    // f(-2) - f(-3) = f(-4)
    // f(-3) - f(-4) = f(-5) -> f(-5) = 5

    mdp[0] = 0;
    mdp[1] = 1;
    mdp[2] = -1;
    mdp[3] = 2;
    for (int i = 4; i <= 1000000; i++)
        mdp[i] = (mdp[i - 2] - mdp[i - 1]) % 1000000000;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;

    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= 1000000; i++)
        dp[i] = (dp[i - 1] + dp[i - 2]) % 1000000000;
    solve();

    int val;
    if (n < 0)
        val = mdp[abs(n)];
    else
        val = dp[n];
    
    if (val > 0)
        cout << 1 << '\n';
    else if (val == 0)
        cout << 0 << '\n';
    else
        cout << -1 << '\n';
    
    cout << abs(val) % 1000000000 << '\n';

    return 0;
}
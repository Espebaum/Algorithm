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
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
using namespace std;

int dp[1001][1001];

// int solve(int n, int k)
// {
//     if (k == 0 || k == n)
//         return 1;
//     return solve(n - 1, k - 1) + solve(n - 1, k);
// }

int solve(int n, int k)
{
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= min(i, k); j++) {
            if (j == 0 || j == i)
                dp[i][j] = 1;
            else 
                dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % 10007;
        }
    }
    return dp[n][k];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int N, K;
    cin >> N >> K;

    int ans = solve(N, K);
    cout << ans;

    return 0;
}
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

int dp[101][101];
int N;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;

    for (int i = 1; i <= 9; i++) {
        dp[1][i] = 1;
    }

    long long d = 1000000000;
    for (int i = 2; i <= N; i++) {
        for (int j = 0; j <= 9; j++) {
            if (j == 0)
                dp[i][j] = dp[i - 1][j + 1];
            else if (j == 9)
                dp[i][j] = dp[i - 1][j - 1];
            else 
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j + 1];
            dp[i][j] %= d;
        }
    }

    long long sum = 0;
    for (int i = 0; i <= 9; i++) {
        sum += dp[N][i];
    }
    sum %= d;
    cout << sum;
    return 0;
}
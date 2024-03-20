#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
const int INF = 0x3f3f3f3f;
using namespace std;

int N;
int dp[101010];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;
    int check = 0;
    for (int i = 4; i <= N; i++) {
        if (sqrt(i) == (int) sqrt(i)) {
            check = i; // check는 제곱근
            dp[i] = 1;
        }
        else {
            dp[i] = INF;
            for (int j = 1; j <= sqrt(i); j++) {
                dp[i] = min(dp[i],dp[j*j] + dp[i - (j*j)]);
            }
        }
    }
    cout << dp[N];
    return 0;
}
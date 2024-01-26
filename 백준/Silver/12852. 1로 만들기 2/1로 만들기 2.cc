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

int N;
int dp[1010101][2];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    dp[1][0] = 0;
    dp[1][1] = 0;
    dp[2][0] = 1;
    dp[2][1] = 1;
    vector<int> t;

    for (int i = 3; i <= N; i++) {
        dp[i][0] = dp[i - 1][0] + 1;
        int rec = dp[i][0]; // 2
        int tmp = i - 1; // 3
        if ((i % 2) == 0) {
            dp[i][0] = min(dp[i / 2][0] + 1, dp[i][0]);
            if (rec != dp[i][0]) {
                tmp = i / 2;
                rec = dp[i][0];
            }
        }
        if ((i % 3) == 0) {
            dp[i][0] = min(dp[i / 3][0] + 1, dp[i][0]);
            if (rec != dp[i][0])
                tmp = i / 3;
        }
        dp[i][1] = tmp;
    }

    cout << '\n';
    cout << dp[N][0] << '\n';
    cout << N << ' ';

    int cur = N;
    for (int i = 0; i < dp[N][0]; i++) {
        cout << dp[cur][1] << ' ';
        cur = dp[cur][1];
    }   

    return 0;
}
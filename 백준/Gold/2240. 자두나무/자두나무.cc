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

int arr[1002];
int dp[1002][32][3]; 
int T, W;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> T >> W;

    for (int i = 1; i <= T; i++)
        cin >> arr[i];

    //dp[i][j][k] i:현재시간 j:이동횟수 k:나무번호 
    for (int i = 1; i <= T; i++) {
        dp[i][0][1] = dp[i - 1][0][1] + (arr[i] == 1 ? 1 : 0);
        for (int j = 1; j <= W; j++) {
            if (i < j)
                break ;
            if (arr[i] == 1) {
                dp[i][j][1] = max(dp[i - 1][j - 1][2], dp[i - 1][j][1]) + 1;
                dp[i][j][2] = max(dp[i - 1][j - 1][1], dp[i - 1][j][2]);
            } else {
                dp[i][j][1] = max(dp[i - 1][j - 1][2], dp[i - 1][j][1]);
                dp[i][j][2] = max(dp[i - 1][j - 1][1], dp[i - 1][j][2]) + 1;
            }
        }
    }
    int ans = 0;
    for (int j = 0; j <= W; j++) {
        ans = max(ans, dp[T][j][1]);
        ans = max(ans, dp[T][j][2]);
    }
    cout << ans;
    return 0;
}
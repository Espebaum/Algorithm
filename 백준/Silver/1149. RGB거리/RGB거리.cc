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
int red[1010];
int green[1010];
int blue[1010];
int dp[1010][3];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> red[i] >> green[i] >> blue[i];
    }

    dp[1][0] = red[1];
    dp[1][1] = green[1];
    dp[1][2] = blue[1];

    for (int i = 2; i <= N; i++) {
        dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + red[i];
        dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + green[i];
        dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + blue[i];
    }
    cout << *min_element(dp[N], dp[N] + 3);

    return 0;
}
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
int dp[100001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    dp[0] = 1;
    dp[1] = 3;

    for (int i = 2; i <= N; i++) {
        dp[i] = (dp[i - 1] * 2 + dp[i - 2])%9901;
    }
    cout << dp[N];
    return 0;
}
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
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
using namespace std;

int N;
long long dp[100];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;

    dp[1] = 1;
    dp[2] = 1;

    for (int i = 3; i <= 90; i++) {
        dp[i] = dp[i - 2] + dp[i - 1];
    }
    cout << dp[N];
    return 0;
}
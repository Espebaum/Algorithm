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
#include <tuple>
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
typedef long long ll;
const int INF = 0x3f3f3f3f;
using namespace std;

long long dp[10010];
int k = 10000;
long long n;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    dp[1] = 1;
    dp[2] = 1;

    for (int i = 3; i < 10010; i++) {
        dp[i] = (dp[i - 2] + dp[i - 1]);
    }

    cout<< dp[n];
    return 0;
}
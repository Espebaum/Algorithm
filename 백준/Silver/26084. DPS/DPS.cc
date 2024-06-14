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

string S;
ll N;
ll karr[26];
ll narr[26];
ll ans = 1;
ll isused[50050];
ll arr[50050];

ll  comb(int n, int k)
{
    ll  dp[n + 1][k + 1];

    for (int i = 0; i <= n; i++)
        fill(dp[i], dp[i] + k, 0);

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= min(i, k); j++) {
            if (j == 0 || j == i) {
                dp[i][j] = 1;
            }
            else {
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
            }
        }
    }

    return dp[n][k];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); std::cout.tie(NULL);
    cin >> S >> N;

    for (int i = 0; i < S.length(); i++)
        karr[(int)S[i] - 65]++;

    for (int i = 0; i < N; i++) {
        string s; cin >> s;
        narr[(int)s[0] - 65]++; 
    }

    bool check = true;
    for (int i = 0; i < 26; i++) {
        if (karr[i] != 0 && narr[i] != 0) {
            ans *= comb(narr[i], karr[i]);
        }
        if (karr[i] != 0 && narr[i] == 0)
            check = false;
    }

    if (check)
        cout << ans;
    else
        cout << 0;

    return 0;
}
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
typedef long long ll;
using namespace std;

string  a;
string  b;
int     dp[1010][1010];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> a;
    cin >> b;

    for (int i = 1; i <= a.length(); i++) {
        for (int j = 1; j <= b.length(); j++) {
            if (a[i - 1] != b[j - 1])
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            else
                dp[i][j] = dp[i - 1][j - 1] + 1;
        }
    }

    cout << dp[a.length()][b.length()];
    return 0;
}
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
const int INF = 0x3f3f3f3f;
using namespace std;

string s1;
string s2;
int dp[1010][1010];
string ans;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>s1>>s2;
    int len1 = s1.length(); // ACAYKP
    int len2 = s2.length(); // CAPCAK
    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            if (s1[i-1] == s2[j-1])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
        }
    }
    cout << dp[len1][len2] << '\n';

    int x = len1;
    int y = len2;

    while (x != 0 && y != 0) {
        if (dp[x][y] == dp[x-1][y]) {
            x -= 1;
        } else if (dp[x][y] == dp[x][y-1]) {
            y -= 1;
        } else {
            ans.push_back(s1[x-1]);
            x -= 1;
            y -= 1;
        }
    }
    reverse(ans.begin(), ans.end());
    cout << ans;

    return 0;
}
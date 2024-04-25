#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
const int INF = 0x3f3f3f3f;
using namespace std;

int n, m;
char board[1010][1010];
int dp[1010][1010];
int mx;
int nr, nc, mn;

void    check(int x, int y) // 3 4
{
    // cout << "x: " << x << " y: " << y << '\n';
    int cnt = dp[x - 1][y - 1]; // 2
    // cout << "cnt: " << cnt << '\n';


    nr = 0; nc = 0; mn = 0;
    for (int i = 0; i <= cnt; i++) {
        if (board[x - i][y] != '0')
            nr++;
        else
            break ;
    }

    for (int i = 0; i <= cnt; i++) {
        if (board[x][y - i] != '0')
            nc++;
        else
            break ;
    }

    // cout << "nr: " << nr << " nc: " << nc << '\n';

    if (nr == nc && nr == cnt + 1) {
        dp[x][y] = dp[x - 1][y - 1] + 1;
    }
    else
        dp[x][y] = min(nr, nc);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++)
            cin >> board[i][j];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (board[i][j] == '0')
                dp[i][j] = 0;
            else
                check(i, j);
            mx = max(mx, dp[i][j]);
        }
    }

    // cout << "BOARD\n";
    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= m; j++)
    //         cout << board[i][j] << ' ';
    //     cout << '\n';
    // }
    // cout << "\nDP\n";
    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= m; j++)
    //         cout << dp[i][j] << ' ';
    //     cout << '\n';
    // }
    
    cout << mx * mx << '\n';

    return 0;
}
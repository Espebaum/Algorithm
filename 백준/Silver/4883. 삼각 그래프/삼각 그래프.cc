#include <bits/stdc++.h>
#include <cmath>
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
const int INF = 0x3f3f3f3f;
using namespace std;

int N;
int board[100010][4];
int dp[100010][4];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int test = 1;
    while (1) {
        cin >> N;
        if (N == 0)
            return 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < 3; j++)
                cin >> board[i][j];
        }
        dp[0][0] = INF; 
        dp[0][1] = board[0][1]; 
        dp[0][2] = dp[0][1] + board[0][2];
        dp[1][0] = board[0][1] + board[1][0];
        dp[1][1] = min({dp[1][0] + board[1][1], dp[0][1] + board[1][1], dp[0][2] + board[1][1]});
        dp[1][2] = min({dp[1][1] + board[1][2], dp[0][1] + board[1][2], dp[0][2] + board[1][2]});
        
        for (int i = 2; i < N; i++) {
            dp[i][0] = min(dp[i - 1][0] + board[i][0], dp[i - 1][1] + board[i][0]);
            dp[i][1] = min({dp[i][0] + board[i][1], dp[i - 1][0] + board[i][1], dp[i - 1][1] + board[i][1], dp[i - 1][2] + board[i][1]});
            dp[i][2] = min({dp[i][1] + board[i][2], dp[i - 1][1] + board[i][2], dp[i - 1][2] + board[i][2]});
        }
        cout << test << ". " << dp[N - 1][1] << '\n';
        test += 1;
    }
    return 0;
}
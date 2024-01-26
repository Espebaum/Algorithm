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

int T;
int board[2][101010];
int dp[2][101010];
int sum;
vector<int> v;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> T;

    while (T--)
    {
        int n;
        cin >> n;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < n; j++)
                cin >> board[i][j];
        }
        dp[0][0] = board[0][0];
        dp[1][0] = board[1][0];
        for (int i = 1; i < n; i++) 
        {
            dp[0][i] = max(dp[1][i - 1], dp[1][i - 2]) + board[0][i]; 
            dp[1][i] = max(dp[0][i - 1], dp[0][i - 2]) + board[1][i];
        }

        cout << max(dp[0][n - 1], dp[1][n - 1]) << '\n';
    }

    return 0;
}
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
const int INF = 0x3f3f3f3f;
using namespace std;

int N;
vector<char>dp(1010);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;
                 // c s c s c s c s c s c s 
    dp[1] = 's'; // 1
    dp[2] = 'c'; // 1 1
    dp[3] = 's'; // 1 1 1
    dp[4] = 'c'; // 1 3
    dp[5] = 's'; // 1 1 3
    dp[6] = 'c'; // 1 3 1 1
                 // 1 1 1 3
                 // 3 3

    for (int i = 7; i <= 1000; i++) {
        if (dp[i - 3] == dp[i - 1] && dp[i - 1] == 'c')
            dp[i] = 's';
        else if (dp[i - 3] == dp[i - 1] && dp[i - 1] == 's')
            dp[i] = 'c';
    }

    if (dp[N] == 'c')
        cout << "CY";
    else
        cout << "SK";

    return 0;
}
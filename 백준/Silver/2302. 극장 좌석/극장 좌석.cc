#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
const int INF = 0x3f3f3f3f;
using namespace std;
typedef long long ll;

int N, M;
// int arr[44];
ll dp[44];
vector<int>vip;
int sum = 1;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    cin >> M;

    for (int i = 0; i < M; i++) {
        int num; cin >> num;
        vip.push_back(num);
    }
    dp[0] = 1; dp[1] = 1;
    dp[2] = 2;

    for (int i = 3; i <= 40; i++)
        dp[i] = dp[i - 1] + dp[i - 2];  

    if (M == 0) {
        cout << dp[N]; return 0;
    }

    for (int i = 0; i < M; i++) {
        if (i == 0) {
            sum *= dp[vip[i] - 1];
        }
        else {
            sum *= dp[vip[i] - (vip[i - 1]) - 1];
        }
    }

    sum *= dp[N - vip[vip.size() - 1]];
    cout << sum << '\n';

    return 0;
}
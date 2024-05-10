#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
const int INF = 0x3f3f3f3f;
using namespace std;

int N, M; // 물건갯수, 최대수용무게
int v[10101]; // 무게
int c[10101]; // 만족도
int k[10101]; // 개수
vector<pair<int,int>>vp;
int dp[2020][10101];
int W[10101];
int V[10101];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;

    for (int i = 1; i <= N; i++)
        cin >> v[i] >> c[i] >> k[i];

    for (int i = 1; i <= N; i++) {
        for (int j = k[i]; j >= 1; j >>= 1) {
            int num = j - (j >> 1);
            vp.push_back({v[i]*num, c[i]*num});
        }
    }

    int nn = vp.size();
    for (int i = 1; i <= nn; i++) {
        W[i] = vp[i-1].first;
        V[i] = vp[i-1].second;
    }

    for (int i = 1; i <= nn; i++) {
        for (int j = 0; j <= M; j++) {
            if (W[i] <= j)
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-W[i]] + V[i]);
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    cout << dp[nn][M];    

    return 0;
}
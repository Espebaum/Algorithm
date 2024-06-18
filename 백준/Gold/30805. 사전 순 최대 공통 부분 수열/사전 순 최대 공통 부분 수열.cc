#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
const int INF = 0x3f3f3f3f;
using namespace std;

int N, M;
vector<int>a;
vector<int>b;
vector<int>dp[110][110];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++) {
        int num; cin >> num;
        a.push_back(num);
    }
    cin >> M;
    for (int i = 0; i < M; i++) {
        int num; cin >> num;
        b.push_back(num);
    }
    vector<int>ans;
    int aidx = 0;
    int bidx = 0;
    int atmp = 0;
    int btmp = 0;
    for (int i = 100; i >= 1; i--)
    {
        for (aidx; aidx < a.size(); aidx++) {
            if (a[aidx] == i) {
                for (bidx; bidx < b.size(); bidx++) {
                    if (b[bidx] == i) {
                        ans.push_back(b[bidx]);
                        bidx++;
                        atmp = aidx; btmp = bidx;
                        break ;
                    }
                }
            }
        }
        aidx = atmp; bidx = btmp;
    }
    cout << ans.size() << '\n';
    if (ans.size() != 0)
        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] << ' ';
    return 0;
}
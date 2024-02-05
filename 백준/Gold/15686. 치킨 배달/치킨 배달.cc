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

int N, M, chick;
int board[55][55];
int comb[15];
int isused[15];
vector<pair<int,int>> hom;
vector<pair<int,int>> chi;
// vector<pair<int, pair<int,int>>> dist;
vector<int> ans;

void check()
{
    int dist = 0;
    int mn = INF;
    for (int i = 0; i < hom.size(); i++) {
        mn = INF;
        for (int j = 0; j < M; j++) {
            mn = min(mn, abs(hom[i].first - chi[comb[j] - 1].first)+ abs(hom[i]. second - chi[comb[j] - 1].second));
        }
        dist += mn;
    }
    ans.push_back(dist);
}

void    solve(int k)
{
    if (k == M) {
        check();
        return ;
    }

    int st = 1;
    if (k != 0)
        st = comb[k - 1] + 1;

    for (int i = st; i <= chick; i++) {
        if (!isused[i]) {
            comb[k] = i;
            isused[i] = 1;
            solve(k + 1);
            isused[i] = 0;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> board[i][j];
            if (board[i][j] == 2) {
                chi.push_back({i, j});
                chick++;
            }
            else if (board[i][j] == 1)
                hom.push_back({i, j});
        }
    }

    solve(0);
    sort(ans.begin(), ans.end());
    cout << ans[0];
    return 0;
}
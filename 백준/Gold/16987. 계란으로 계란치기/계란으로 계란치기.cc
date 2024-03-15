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

int N, ans;
vector<pair<int,int>> eggs;

void    solve(int idx, int broken)
{
    if (idx == N) {
        ans = max(ans, broken);
        return ;
    }

    if (eggs[idx].first <= 0) {
        solve(idx + 1, broken);
    } else {
        bool hit = false;
        for (int i = 0; i < N; i++) {
            if (i != idx && eggs[i].first > 0) {
                hit = true;
                eggs[idx].first -= eggs[i].second;
                eggs[i].first -= eggs[idx].second;

                int nbroken = broken + (eggs[idx].first <= 0) + (eggs[i].first <= 0);
                solve(idx + 1, nbroken);
                eggs[idx].first += eggs[i].second;
                eggs[i].first += eggs[idx].second;
            }
        }
        if (!hit) {
            solve(idx + 1, broken);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); std::cout.tie(NULL);
    cin >> N;
    eggs.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> eggs[i].first >> eggs[i].second;
    }
    solve(0, 0);
    cout << ans << '\n';

    return 0;
}
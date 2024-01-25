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
using namespace std;

int N;
vector<pair<int,int>> vp;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;

    for (int i = 0; i < N; i++) {
        int x, y, a, b; cin >> x >> y >> a >> b;
        int start = x * 100 + y;
        int end = a * 100 + b;
        vp.push_back({start, end});
    }
    sort(vp.begin(), vp.end());

    // for (int i = 0; i < N; i++) {
    //     cout << vp[i].first << ' ' << vp[i].second << '\n';
    // } 

    int t = 301;
    int ans = 0;
    while (t < 1201)
    {
        int nxt_t = t;
        for (int i = 0; i < N; i++) {
            if (vp[i].first <= t && vp[i].second > nxt_t)
                nxt_t = vp[i].second;
        }
        if (nxt_t == t) {
            cout << 0;
            return 0;
        }
        ans++;
        t = nxt_t;
    }
    cout << ans;
    return 0;
}
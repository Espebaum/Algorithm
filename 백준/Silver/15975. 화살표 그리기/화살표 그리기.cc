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
#include <set>
#include <climits>
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
typedef long long ll;
const int INF = 0x3f3f3f3f;
using namespace std;

int N;
set<pair<int, int>>dots;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); std::cout.tie(NULL);
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int x, y; cin >> x >> y;
        dots.insert({y, x});
    }

    // for (auto k: dots)
    //     cout << k.first << ' ' << k.second << '\n';

    ll ans = 0;
    for (auto k = dots.begin(); k != dots.end(); k++)
    {
        auto first = k->first; auto second = k->second;
        // cout <<"first: " << first<< " second: " << second << '\n';
        auto check = k;
        if (check == dots.begin()) {
            ++check;
            auto new_first = check->first;
            auto new_second = check->second;
            if (first == new_first) {
                // cout << "val: " << abs(new_second - second) << '\n';
                ans += abs(new_second - second);
            }
        }
        else if (next(check) == dots.end()) {
            --check;
            auto new_first = check->first;
            auto new_second = check->second;
            if (first == new_first) {
                // cout << "val: " << abs(new_second - second) << '\n';
                ans += abs(new_second - second);
            }
        }
        else {
            int pl = INT_MAX;
            int mi = INT_MAX;
            // cout << "pl: " << pl << " mi: " << mi << '\n';
            auto check_m = k;
            ++check;
            auto new_first1 = check->first;
            auto new_second1 = check->second;
            if (first == new_first1) {
                pl = abs(new_second1 - second);
            }
            --check_m;
            auto new_first2 = check_m->first;
            auto new_second2 = check_m->second;
            if (first == new_first2)
                mi = abs(new_second2 - second);
            if (pl == INT_MAX && mi == INT_MAX)
                ;
            else if (pl == INT_MAX)
                ans += mi;
            else if (mi == INT_MAX)
                ans += pl;
            else if (pl >= mi)
                ans += mi;
            else if (pl < mi)
                ans += pl;
        }

    }   
    cout << ans;

    return 0;
}
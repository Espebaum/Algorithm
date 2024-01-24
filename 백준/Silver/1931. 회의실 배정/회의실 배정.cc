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

bool compare(pair<int,int>a, pair<int, int>b)
{
    if (a.second == b.second)
        return a.first < b.first;
    return a.second < b.second;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int x, y; cin >> x >> y;
        vp.push_back({x, y});
    }
    sort(vp.begin(), vp.end(), compare);

    int time = vp[0].second;
    int ans = 1;
    for (int i = 1; i < N; i++)
    {
        if (vp[i].first >= time) {
            ans++;
            time = vp[i].second;
        }
    }
    cout << ans << '\n';
    
    return 0;
}
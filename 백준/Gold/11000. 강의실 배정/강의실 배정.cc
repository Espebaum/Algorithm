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
vector<pair<int, int>> vp;
priority_queue<int, vector<int>, greater<int>> pq;

bool compare(pair<int,int> a, pair<int,int> b)
{
    return a.first < b.first;
}

int solve(int k)
{
    pq.push(vp[0].second);
    for (int i = 1; i < vp.size(); i++) {
        pq.push(vp[i].second);
        if (pq.top() <= vp[i].first)
            pq.pop();
    }
    return pq.size();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++) {
        int x, y; cin >> x >> y;
        vp.push_back({x, y});
    }
    sort(vp.begin(), vp.end(), compare);
    cout << solve(N) << '\n';
}
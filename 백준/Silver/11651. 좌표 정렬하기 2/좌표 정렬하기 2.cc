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
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
typedef long long ll;
using namespace std;

int N;
vector< pair<int, int> > v;

bool compare(pair<int, int> a, pair<int, int> b) {
    if (a.second != b.second)
        return a.second < b.second;
    else
        return a.first < b.first;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++) {
        int x, y; 
        cin >> x >> y;
        v.push_back(make_pair(x, y));
    }

    sort(v.begin(), v.end(), compare);

    for (int i = 0; i < N; i++) {
        cout << v[i].first << ' ' << v[i].second << '\n';
    }

    return 0;
}
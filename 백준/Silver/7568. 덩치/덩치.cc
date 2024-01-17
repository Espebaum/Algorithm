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
vector< pair<int, int> > p;
vector<int> d;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int x, y;
        cin >> x >> y;
        p.push_back(make_pair(x, y));
    }
 
    for (int i = 0; i < N; i++) {
        int weight = p[i].first;
        int height = p[i].second;
        int ans = 1;
        for (int j = 0; j < N; j++) {
            if (i == j)
                continue;
            if (p[j].first > p[i].first && p[j].second > p[i].second)
                ans++;
        }
        d.push_back(ans);
    }
    for (int i = 0; i < d.size(); i++)
        cout << d[i] << ' ';
    return 0;
}
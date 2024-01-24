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

int N, K;
// int t[200020];
int vis[200020];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> K;

    // fill(t, t+200020, -1);
    // t[N] = 0;
    deque<int> d;
    d.push_back(N);
    vis[N] = 1;

    while (!d.empty())
    {
        int cur = d.front(); d.pop_front();
        if (cur == K)
            break ;
        if (cur * 2 < 100001 && !vis[cur * 2]) {
            d.push_front(cur * 2);
            vis[cur * 2] = vis[cur];
        }
        if (cur - 1 >= 0 && !vis[cur - 1]) {
            d.push_back(cur - 1);
            vis[cur - 1] = vis[cur] + 1;
        } 
        if (cur + 1 < 100001 && !vis[cur + 1]) {
            d.push_back(cur + 1);
            vis[cur + 1] = vis[cur] + 1;
        }
    }
    // for (int i = 0; i < K; i++)
        // cout << "i: " << i << " val: " << vis[i] << '\n';
    cout << vis[K] - 1;
    return 0;
}
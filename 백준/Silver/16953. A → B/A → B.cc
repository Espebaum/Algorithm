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

long long A, B;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> A >> B;
    queue< pair<ll, ll> > q;
    q.push(make_pair(A, 1));
    ll ans = -1;
    while (!q.empty())
    {
        ll  k = q.front().first;
        ll  cnt = q.front().second;
        q.pop();
        if (k == B) {
            ans = cnt;
            break;
        }
        if (2 * k <= B)
            q.push(make_pair(2*k, cnt+1));
        if (10 * k <= B)
            q.push(make_pair(10*k + 1, cnt + 1));
    }
    cout << ans;
    return 0;
}
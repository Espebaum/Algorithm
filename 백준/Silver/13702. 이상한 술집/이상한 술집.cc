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

ll N, K; // 주전자의 개수(N), 친구들의 수(K)
ll arr[10101];

bool    solve(int x) // 결정함수
{
    int cur = 0;
    for (int i = 0; i < N; i++)
        cur += arr[i] / x;
    return cur >= K;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); std::cout.tie(NULL);

    cin >> N >> K;

    for (int i = 0; i < N; i++)
        cin >> arr[i];
    
    ll st = 0;
    ll en = pow(2, 31) - 1;
    while (st < en)
    {
        ll mid = (st + en + 1) / 2; // 매개변수
        if (solve(mid))
            st = mid;
        else
            en = mid - 1;
    }
    cout << st;
    return 0;
}
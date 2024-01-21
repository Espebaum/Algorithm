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

ll N, M;
ll arr[1010101];
vector<int> v;

ll solve(ll mid, ll idx)
{
    ll sum = 0;
    for (int i = idx; i < N; i++)
        sum += arr[i] - mid;
    return sum;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    sort(arr, arr+N);

    ll st = 0;
    ll en = arr[N - 1];
    ll mid;
    ll idx;

    while (st <= en)
    {
        mid = (st + en) / 2;
        idx = lower_bound(arr, arr + N, mid) - arr;
        ll tmp = lower_bound(arr, arr + N, mid + 1) - arr;
        if (solve(mid, idx) >= M && solve(mid + 1, tmp) < M) {
            cout << mid;
            return 0;
        } else if (solve(mid, idx) < M) {
            en = mid - 1; 
        } else if (solve(mid, idx) > M) {
            st = mid + 1;
        } 
    }
    return 0;
}
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
#include <climits>
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
typedef long long ll;
using namespace std;

int K, N;
int arr[10010];

bool    solve(ll x)
{
    ll cur = 0;
    for (int i = 0; i < K; i++)
        cur += arr[i] / x;
    return cur >= N;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> K >> N;
    for (int i = 0; i < K; i++) {
        cin >> arr[i];
    }
    ll st = 1;
    ll en = pow(2, 31) - 1;
    while (st < en)
    {
        ll mid = (st + en + 1) / 2;
        if (solve(mid))
            st = mid;
        else
            en = mid - 1;
    }
    cout << st;
    return 0;
}
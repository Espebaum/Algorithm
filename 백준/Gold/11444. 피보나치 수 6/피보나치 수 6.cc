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

map<ll, ll> m;
ll N;
ll mod = 1000000007;

ll f(ll k)
{
    if (m[k])
        return m[k];
    long long result;
    if (k % 2 == 0) {
        result = f(k/2) * (f(k/2+1) + f(k/2-1)) % mod;
    } else {
        result = ((f((k+1)/2)*f((k+1)/2)) % mod) + (f((k-1)/2)*f((k-1)/2) % mod) % mod;
    }
    return m[k] = result % mod;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;

    m[0] = 0;
    m[1] = 1;
    m[2] = 1;
    cout << f(N);
    return 0;
}
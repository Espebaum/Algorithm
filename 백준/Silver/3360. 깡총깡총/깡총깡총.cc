#include <iostream>

using namespace std;
typedef long long ll;

const ll MOD = 1000000;

int main()
{
    ll n;
    cin >> n;

    ll ans = 0;
    for (ll x = 0; 3 * x <= n; x++) {
        ans += (n - 3 * x) / 2 + 1;
    }
    cout << ans % MOD;
    return 0;
}

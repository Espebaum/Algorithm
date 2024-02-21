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

double k;

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> k;
    int mo = pow(10, 9);
    double ans = k * mo;
    if (ans != (int) ans) {
        cout << "NO";
        return 0;
    }
    int g = gcd(ans, mo);
    ans /= g;
    mo /= g;
    cout << "YES\n";
    cout << ans << ' ' << mo;
    return 0;
}
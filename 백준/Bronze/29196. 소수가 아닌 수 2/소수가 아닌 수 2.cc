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
double l, p, q;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> k;
    p = 1; q = 1; l = pow(10, -6);
    while (1)
    {
        double value = (double) p / q;
        if (abs(value - k) < l)
            break ;
        if (value > k)
            q += 1;
        else
            p += 1;
    }
    cout << "YES\n";
    cout << p << ' ' << q;
    return 0;
}
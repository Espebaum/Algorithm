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

int T;
int M, N, x, y;

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int lcm(int a, int b)
{
    return (a * b) / gcd(a, b);
}

void    check()
{
    int res = -1;

    for (int i = x; i <= lcm(M, N); i += M) {
        int ny = i % N;

        if (ny == 0)
            ny = N;
            
        if (ny == y) {
            res = i;
            break ;
        }
    }

    cout << res << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> T;

    while (T--)
    {
        cin >> M >> N >> x >> y;
        check();
    }

    return 0;
}
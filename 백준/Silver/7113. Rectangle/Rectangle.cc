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
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
using namespace std;

int sum;

void    solve(int n, int m)
{
    if (n == 1 || m == 1) {
        int mx = max(n, m);
        sum += mx;
        return ;
    }

    if (n > m)
    {
        n -= m;
        sum++;
        solve(n, m);
    }
    else if (m > n)
    {
        m -= n;
        sum++;
        solve(n, m);
    }
    else {
        sum++;
        return ;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int N, M;
    cin >> N >> M;

    solve(N, M);
    cout << sum;
    return 0;
}
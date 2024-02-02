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

ll P;
ll N, M;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> P;

    while (P--)
    {
        cin >> N >> M;

        ll m1 = 0;
        ll m2 = 1;
        ll cnt = 0;

        while (1) 
        {
            if (m1 == 0 && m2 == 1 && cnt != 0)
                break ;
            ll temp = m1;
            m1 = m2;
            m2 = (temp + m1) % M;
            cnt++;
        }
        cout << N << ' ' << cnt << '\n';
    }

    return 0;
}
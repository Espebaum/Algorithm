#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
const int INF = 0x3f3f3f3f;
using namespace std;
typedef long long ll;

int N, M;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    
    ll fac = 1;
    if (N < M)
        for (int i = 1; i <= N; i++)
            fac = (fac * i) % M;
    else {
        cout << 0;
        return 0;
    }
    cout << fac;
    return 0;
}
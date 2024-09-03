#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define int long long
const int INF = 0x3f3f3f3f;
using namespace std;

int N, M;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;

    int mx = 0;

    if (N == 1 && M == 1) {
        cout << 1 << '\n';
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++)
                cout << ((i % 2) + (j % 2) + 1) << ' ';
            cout << '\n';
        }
    }
    
    else if (N == 1 || M == 1) {
        cout << 2 << '\n';
        mx = 2;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++)
                cout << ((i % 2) + (j % 2) + 1) << ' ';
            cout << '\n';
        }
    }
    
    else {
        cout << 4 << '\n';
        mx = 4;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++)
                cout << ((i % 2) * 2 + (j % 2) + 1) << ' ';
            cout << '\n';
        }
    }    
    return 0;
}
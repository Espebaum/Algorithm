#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
const int INF = 0x3f3f3f3f;
using namespace std;

int T;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> T;

    for (int i = 0; i < T; i++) {
        string a, b;
        cin >> a >> b;
        cout << "Distances: "; 
        for (int i = 0; i < a.length(); i++) {
            if (a[i] <= b[i])
                cout << b[i] - a[i] << ' ';
            else
                cout << b[i] + 26 - a[i] << ' ';
        }
        cout << '\n';
    }

    return 0;
}
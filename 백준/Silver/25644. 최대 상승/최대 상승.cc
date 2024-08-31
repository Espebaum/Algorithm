#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define int long long
const int INF = 0x3f3f3f3f;
using namespace std;

int N;
int arr[200200];

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    int cur;
    int mx = 0;
    for (int i = 0; i < N; i++) {
        if (i == 0)
            cur = arr[0];
        else {
            if (cur > arr[i])
                cur = arr[i];
            else 
                mx = max(mx, arr[i] - cur);
        }
    }
    cout << mx;
    return 0;
}
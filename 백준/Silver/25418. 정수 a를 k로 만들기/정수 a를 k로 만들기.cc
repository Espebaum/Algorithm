#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define int long long
const int INF = 0x3f3f3f3f;
using namespace std;

int A, K;
int arr[1001010];

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> A >> K;
    queue<int> q;
    fill(arr, arr+1001010, -1);
    arr[A] = 0;
    q.push(A);

    while (!q.empty())
    {
        int cur = q.front(); q.pop();
        if (cur == K)
            break;
        for (int dir = 0; dir < 2; dir++)
        {
            int ncur;
            if (dir == 0)
                ncur = cur + 1;
            else
                ncur = cur * 2;
            if (ncur < 0 || ncur > 1000010 || arr[ncur] >= 0)
                continue;
            arr[ncur] = arr[cur] + 1;
            q.push(ncur);
        }
    }
    cout << arr[K];
    return 0;
}
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
const int INF = 0x3f3f3f3f;
using namespace std;

int n, w, L;
int bridge[1010];
queue<int> q;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> w >> L;
    for (int i = 0; i < n; i++) {
        cin >> bridge[i];
    }

    int time = 0, total = 0;
    for (int i = 0; i < n; i++) 
    {
        while (1) {
            if (q.size() == w) {
                total -= q.front();
                q.pop();
            }
            if (total + bridge[i] <= L)
                break ;
            q.push(0);
            time++;
        }
        q.push(bridge[i]);
        total += bridge[i];
        time++;
    }
    cout << time + w << '\n';
    return 0;
}

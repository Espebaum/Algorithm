#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define int long long
const int INF = 0x3f3f3f3f;
using namespace std;

queue<int>q;
int N;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    while (N--)
    {
        string s; cin >> s;
        if (s == "push") {
            int num; cin >> num;
            q.push(num);
        } else if (s =="front") {
            if (q.empty()) 
                cout << -1 << '\n';
            else
                cout << q.front() << '\n';
        } else if (s == "back") {
            if (q.empty())
                cout << -1 << '\n';
            else
                cout << q.back() << '\n';
        } else if (s == "size") {
            cout << q.size() << '\n';
        } else if (s == "pop") {
            if (q.empty()) {
                cout << -1 << '\n';
            } else {
                int t = q.front();
                q.pop();
                cout << t << '\n';
            }
        } else {
            if (q.empty())
                cout << 1 << '\n';
            else 
                cout << 0 << '\n';
        }
    }
    return 0;
}
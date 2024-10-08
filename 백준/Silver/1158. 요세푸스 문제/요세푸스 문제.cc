#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define int long long
const int INF = 0x3f3f3f3f;
using namespace std;

int N, K;
list<int>l;
vector<int>v;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> K;

    for (int i = 1; i <= N; i++)
        l.push_back(i);
    auto cursor = l.begin();

    while (!l.empty())
    {
        for (int i = 1; i < K ; i++) {
            cursor++;
            if (cursor == l.end())
                cursor = l.begin();
        }
        v.push_back(*cursor);
        cursor = l.erase(cursor);
        if (cursor == l.end())
            cursor = l.begin();
    }

    cout << "<";
    for (int i = 0; i < v.size(); i++){
        cout << v[i];
        if (i != v.size() - 1)
            cout << ", ";
    }
    cout << ">";

    return 0;
}
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define int long long
const int INF = 0x3f3f3f3f;
using namespace std;

int tc;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> tc;

    while (tc--)
    {
        list<char> d;
        string s; cin >> s;
        auto cursor = d.begin();
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '<') {
                if (cursor != d.begin())
                    cursor--;
            }
            else if (s[i] == '>') {
                if (cursor != d.end())
                    cursor++;
            }
            else if (s[i] == '-') {
                if (cursor != d.begin()) {
                    cursor = d.erase(prev(cursor));
                }
            }
            else {
                d.insert(cursor, s[i]);
            }
            // cout << "word: " << s[i] << '\n';
            // cout << "cursor: " << cursor << '\n';
            // for (int i = 0; i < s.length(); i++)
            //     cout << (char) d[i];
            // cout <<'\n';          
        }
        for (list<char>::iterator it = d.begin(); it != d.end(); ++it)
        {
            cout << *it;
        }
        cout << '\n';
    }
    return 0;
}
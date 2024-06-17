#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
const int INF = 0x3f3f3f3f;
using namespace std;
typedef long long ll;

ll X;
int len;
string s;
vector<string>vs;
string origin;
bool enf = false;

string  mix()
{
    string  fr;
    stack<char> en;

    for (int i = 0; i < len; i++)
    {
        if (i % 2 == 0) {
            fr.push_back(s[i]);
        } else {
            en.push(s[i]);
        }
    }
    while (!en.empty()) {
        char c = en.top(); en.pop();
        fr.push_back(c);
    }
    return fr;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> X >> s;
    origin = s;

    vs.push_back(s);
    len = s.length();

    while (1) {
        string nx = mix();
        if (nx == origin)
            break ;
        vs.push_back(nx);
        s = nx;
    }

    // cout << vs.size() << '\n';
    int mod = X % (vs.size());
    // for (int i = 0; i < vs.size(); i++) {
    //     cout << vs[i] << '\n';
    // }

    cout << vs[mod];
    return 0;
}
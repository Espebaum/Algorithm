#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
using namespace std;

string s;
string b;
string tmp;

stack<char>sc;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> s >> b;

    for (int i = 0; i < s.length(); i++) {
        tmp += s[i];
        if (tmp.back() == b.back()) {
            bool c = true;
            if (tmp.size() < b.size())
                continue ;
            for (int j = 0; j < b.size(); j++) {
                if (tmp[tmp.size() - b.size() + j] != b[j]) {
                    c = false;
                    break ;
                }
            }
            if (c) {
                for (int j = 0; j < b.size(); j++) tmp.pop_back();
            }
        }
    }
    if (tmp.empty())
        cout << "FRULA";
    else
        cout << tmp;
    return 0;
}
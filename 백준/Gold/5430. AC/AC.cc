#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
// #define int long long
const int INF = 0x3f3f3f3f;
using namespace std;

int tc;
int siz; 
deque<int>d;
string c;
int r_flag = 0;

void    move()
{
    r_flag = 0;
    for (size_t i = 0; i < c.length(); i++) 
    {
        if (c[i] == 'R') {
            if (r_flag == 0)
                r_flag = 1;
            else
                r_flag = 0;
        }
        else {
            if (d.empty()) {
                cout << "error\n";
                return ;
            }
            else {
                if (r_flag == 0)
                    d.pop_front();
                else
                    d.pop_back();
            }
        }
    }
    cout << "[";
    if (r_flag == 0) {
        for (size_t i = 0; i < d.size(); i++) {
            cout << d[i];
            if (i != d.size() - 1)
                cout << ",";
        }
    } else {
        int size = d.size() - 1;
        for (int i = size; i >= 0; i--) {
            cout << d[i];
            if (i != 0)
                cout << ",";
        }
    }
    cout << "]\n";
    d.clear();
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> tc;

    while (tc--)
    {
        cin >> c;
        cin >> siz;
        string l; cin >> l;
        if (siz != 0) {
            int flag = 0;
            int num = -1;
            for (size_t i = 0; i < l.size(); i++) {           
                if (l[i] - '0' >= 0 && l[i] - '0' <= 9) {
                    if (flag == 0) {
                        num = 0;
                        flag = 1;
                        num = (10 * num) + (l[i] - '0');
                    }
                    else
                        num = (10 * num) + (l[i] - '0');
                } else {
                    if (num != -1)
                        d.push_back(num);
                    flag = 0;
                }
            }
        }
        move();
    }
    return 0;
}
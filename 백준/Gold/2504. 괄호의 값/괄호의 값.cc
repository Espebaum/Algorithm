#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define int long long
const int INF = 0x3f3f3f3f;
using namespace std;

string s;
stack<char> st;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> s;
    int sum = 0;
    int num = 1;

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(') {
            num *= 2;
            st.push(s[i]);
        } else if (s[i] == '[') {
            num *= 3;
            st.push(s[i]);
        } else if (s[i] == ')') {
            if (st.empty() || st.top() != '(') {
                cout << 0; return 0;
            } 
            if (s[i - 1] == '(')
                sum += num;
            st.pop();
            num /= 2;
        } else if (s[i] == ']') {
            if (st.empty() || st.top() != '[') {
                cout << 0;
                return 0;
            }
            if (s[i - 1] == '[')
                sum += num;
            st.pop();
            num /= 3;
        }
    }
    if (st.empty())
        cout << sum;
    else
        cout << 0;
    return 0;
}
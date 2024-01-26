#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <list>
#include <utility>
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
using namespace std;

string  s;
stack<char> st;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>s;
    int sum = 0;
    int num = 1;

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(') {
            num *= 2;
            st.push(s[i]);
        }
        else if (s[i] == '[') {
            num *= 3;
            st.push(s[i]);
        }
        else if (s[i] == ')') {
            if (st.empty() || st.top() != '(') {
                cout << 0;
                return 0;
            }
            if (s[i - 1] == '(')
            {
                sum += num;
            }
            st.pop();
            num /= 2;
        }
        else {
            if (st.empty() || st.top() != '[') {
                cout << 0;
                return 0;
            }
            if (s[i - 1] == '[')
            {
                sum += num;
            }
            st.pop();
            num /= 3;
        }
    }

    if (st.empty())
        cout << sum;
    else
        cout << 0;
}

//       ( ( ) [ [  ]  ]  )  (  [  ]  ) 
// sum 0     4      22             28 
// num 1 2 4 2 6 18 6  2  1  2  6  2  1
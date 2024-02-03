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
#include <cmath>
#include <tuple>
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
typedef long long ll;
const int INF = 0x3f3f3f3f;
using namespace std;

string  s;
stack<char> sc;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> s;

    for (int i = 0; i < s.length(); i++)
    {
        char c = s[i];
        if (c >= 'A' && c <= 'Z') // 문자열은 그냥 출력
            cout << c;
        else
        {
            if (c == '(') // '(' 그냥 넣어줌, 우선순위 1등
                sc.push(c);
            else if (c == '*' || c == '/') {
                while (!sc.empty() && (sc.top() == '*' || sc.top() == '/')) 
                {
                    cout << sc.top();
                    sc.pop();
                }
                sc.push(c);
            }
            else if (c == '+' || c == '-') {
                while (!sc.empty() && sc.top() != '(') 
                {
                    cout << sc.top();
                    sc.pop();
                }
                sc.push(c);
            }
            else if (c == ')') {
                while (!sc.empty() && sc.top() != '(') 
                {
                    cout << sc.top();
                    sc.pop();
                }
                sc.pop(); // '(' pop해줌
            }
        }
    }
    while (!sc.empty()) {
        cout << sc.top();
        sc.pop();
    }
    return 0;
}
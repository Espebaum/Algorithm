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
#include <fstream>
#include <sstream>
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
using namespace std;


void    checkBracket(string s)
{
    stack<char> sc;

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{')
            sc.push(s[i]);
        else if (s[i] == ')')
        {
            if (sc.empty() || sc.top() != '(') {
                cout << "no\n";    
                return ;
            }
            else
                sc.pop();
        }
        else if (s[i] == ']')
        {
            if (sc.empty() || sc.top() != '[') {
                cout << "no\n";    
                return ;
            }
            else
                sc.pop();
        }
        else if (s[i] == '}')
        {
            if (sc.empty() || sc.top() != '{') {
                cout << "no\n";    
                return ;
            }
            else
                sc.pop();
        }
    }
    if (sc.empty())
        cout << "yes\n";
    else
        cout << "no\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    string  text = "";

    while (1)
    {
        getline(cin, text);
        if (text == ".")
            break ;
        checkBracket(text);
    }

    return 0;
}
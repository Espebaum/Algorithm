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
#include <sstream>
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
using namespace std;

int tc;

//1234
//1234

void    reverseDiscard(deque<int>& d, string s)
{
    int r_flag = 0;

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == 'R')
        {
            if (r_flag == 0)
                r_flag = 1;
            else
                r_flag = 0;
        }
        else if (s[i] == 'D')
        {
            if (d.size() == 0)
            {
                cout << "error\n";
                return;
            }
            if (r_flag == 0)
                d.pop_front();
            else
                d.pop_back();
        }
    }
    
    cout << "[";
    if (r_flag == 0)
    {
        for (int i = 0; i < d.size(); i++)
        {
            cout << d[i];
            if (i != d.size() - 1)
                cout << ',';
        }
    }
    else
    {
        for (int i = d.size() - 1; i >= 0; i--)
        {
            cout << d[i];
            if (i != 0)
                cout << ',';
        }    
    }
    cout << "]\n";
}

void    solve()
{
    string  s; cin >> s;
    int size; cin >> size;

    string  tmp; cin >> tmp;
    deque<int> d;

    string n = "";
    for (int i = 0; i < tmp.length(); i++) 
    {
        if (tmp[i] == '[' || tmp[i] == ']')
            continue ;
        else if (tmp[i] == ',')
        {
            if (n != "")
            {
                int number = stoi(n);
                d.push_back(number);
            }
            n = "";
        }
        else
        {
            n.push_back(tmp[i]);
            if (i == tmp.size() - 2)
            {
                int number = stoi(n);
                d.push_back(number);
            }
        }
    }

    reverseDiscard(d, s);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> tc;

    while (tc--)
        solve();

    return 0;
}
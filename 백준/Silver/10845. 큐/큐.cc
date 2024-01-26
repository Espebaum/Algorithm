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

int N;
queue<int>  q;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;

    while (N--)
    {
        string  s;
        cin >> s;
        if (s == "push")
        {
            int num; cin >> num;
            q.push(num);
        }
        else if (s == "pop")
        {
            if (q.empty())
                cout << -1 << '\n';
            else
            {
                int top = q.front(); q.pop();
                cout << top << '\n';
            }
        }
        else if (s == "size")
            cout << q.size() << '\n';
        else if (s == "empty")
            cout << q.empty() << '\n';
        else if (s == "front")
        {
            if (q.empty())
                cout << -1 << '\n';
            else 
                cout << q.front() << '\n';
        }
        else
        {
            if (q.empty())
                cout << -1 << '\n';
            else 
                cout << q.back() << '\n';
        }
    }
    return 0;
}
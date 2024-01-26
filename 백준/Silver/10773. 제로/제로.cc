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

int tc;
int sum;
stack<int>  s;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> tc;

    while (tc--)
    {
        int num;
        cin >> num;
        if (num != 0)
        {
            s.push(num);
            sum += num;
        }
        else
        {
            int t = s.top();
            sum -= t;
            s.pop();
        }
    }
    cout << sum;
    return 0;
}
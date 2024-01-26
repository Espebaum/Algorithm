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
    int ans = 0;

    for (int i = 1; i <= N; i++)
        q.push(i);

    while (1)
    {
        if (q.size() == 1)
        {
            ans = q.front();
            break;
        }
        else
        {
            q.pop();
            int top = q.front();
            q.pop();
            q.push(top);
        }
    }
    cout << ans;
    return 0;
}
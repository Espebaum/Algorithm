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

int N, M, sum;
deque<int>  d;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N; cin >> M;

    for (int i = 1; i <= N; i++)
        d.push_back(i);

    while (M--)
    {
        int t;
        cin >> t;   
        int idx = find(d.begin(), d.end(), t) - d.begin();
        while (d.front() != t)
        {
            if (idx < d.size() - idx) {
                d.push_back(d.front());
                d.pop_front();
            }
            else {
                d.push_front(d.back());
                d.pop_back();
            }
            sum++;
        }
        d.pop_front();
    }
    cout << sum;
    return 0;
}
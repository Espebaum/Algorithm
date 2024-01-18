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
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
typedef long long ll;
using namespace std;

int T;
deque<int> d;

bool compare(int a, int b) {
    return a > b;
}

void    solve(queue< pair<int, int> > qp, int m)
{
    sort(d.begin(), d.end(), compare);
    int num = 0;
    while (!qp.empty())
    {
        if (qp.front().first != *d.begin()) {
            int first = qp.front().first;
            int second = qp.front().second;
            qp.pop();
            qp.push(make_pair(first, second));
        } else {
            num++;
            if (qp.front().second == m) {
                cout << num << '\n';
                return ;
            }
            qp.pop();
            d.pop_front();
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> T;

    while (T--)
    {
        int N, M;
        cin >> N >> M;
        queue< pair<int, int> > qp;
        for (int i = 0; i < N; i++) {
            int num; cin >> num;
            d.push_back(num);
            qp.push(make_pair(num, i));
        }
        solve(qp, M);
        while (!qp.empty())
            qp.pop();
        while (!d.empty())
            d.pop_front();
    }
    return 0;
}
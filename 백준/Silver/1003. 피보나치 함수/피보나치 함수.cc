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
vector< pair<int, int> > pv;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;

    pv.push_back(make_pair(1, 0));
    pv.push_back(make_pair(0, 1));

    for (int i = 2; i <= 40; i++) {
        int first = pv[i - 1].first + pv[i - 2].first;
        int second = pv[i - 1].second + pv[i - 2].second;
        pv.push_back(make_pair(first, second));
    }

    while (N--) {
        int num; cin >> num;
        cout << pv[num].first << ' ' << pv[num].second << '\n';
    }

    return 0;
}
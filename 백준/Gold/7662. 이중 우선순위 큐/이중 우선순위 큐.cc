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
#include <set>
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
typedef long long ll;
using namespace std;

int T;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> T;
    while (T--)
    {
        int k;
        cin >> k;
        multiset<int> ms;
        while (k--)
        {
            char    com;
            cin >> com;
            if (com == 'D') {
                int q;
                cin >> q;
                if (ms.empty())
                    continue;
                if (q == 1)
                    ms.erase(prev(ms.end()));
                else
                    ms.erase(ms.begin());
            }
            else {
                int q;
                cin >> q;
                ms.insert(q);
            }
        }
        if (ms.empty())
            cout << "EMPTY\n";
        else {
            cout << *prev(ms.end()) << ' ' << *ms.begin() << '\n';
        }
    }

    return 0;
}
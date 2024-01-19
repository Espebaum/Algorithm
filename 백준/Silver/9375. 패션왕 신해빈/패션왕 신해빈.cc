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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> T;
    while (T--)
    {
        map<string, int> ootd;
        int n; cin >> n;
        string a, b;
        for (int i = 0; i < n; i++) {
            cin >> a >> b;
            if (ootd.find(b) == ootd.end())
                ootd.insert(make_pair(b, 1));
            else
                ootd[b]++;
        }
        int sum = 1;
        for (map<string, int>::iterator i = ootd.begin(); i != ootd.end(); i++)
            sum *= (i->second) + 1;
        cout << --sum << '\n';
    }

    return 0;
}
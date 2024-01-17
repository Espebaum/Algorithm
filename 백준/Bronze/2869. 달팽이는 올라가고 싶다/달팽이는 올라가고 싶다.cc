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

ll A, B, V;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> A >> B >> V;
    double val = (double) (V - B) / (A - B);

    if (val != (ll) val)
        val = ceil(val);

    cout << (ll)val;
    return 0;
}
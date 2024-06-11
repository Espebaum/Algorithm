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
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
typedef long long ll;
const int INF = 0x3f3f3f3f;
using namespace std;

int T;
ll N;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); std::cout.tie(NULL);
    cin >> T;
    bool cake = false;
    while (T--)
    {
        cake = false;
        cin >> N;
        
        if (N % 9 == 0 || N % 3 == 2) {
            cout << "TAK\n";
            cake = true;
        }

        if (!cake)
            cout << "NIE\n";
    }
    return 0;
}
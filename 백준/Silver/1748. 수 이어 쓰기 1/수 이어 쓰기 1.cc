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

int N;
int ans;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); std::cout.tie(NULL);

    cin >> N;
    int num = N;
    int j = 0;

    while (num)
    {
        num /= 10;
        j++;
    }
    // cout << "j: " << j << '\n';
    int rest = N - pow(10, j - 1) + 1;
    // cout << "rest: " << rest << '\n';

    for (int i = 1; i <= j; i++) {
        if (i != j)
            ans += (pow(10, i) - pow(10, i - 1)) * i;
        else
            ans += rest * i;
        // cout << "ans: " << ans << '\n';
    }
    cout << ans << '\n';

    return 0;
}
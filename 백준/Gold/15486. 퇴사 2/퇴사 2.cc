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
using namespace std;

int N;
int ti[1500005], pay[1500005], sum[1500005];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> ti[i] >> pay[i];

    for (int i = 1; i <= N; i++) {
        sum[i] = max(sum[i], sum[i - 1]);

        if (i + ti[i] - 1 <= N) {
            sum[i + ti[i]] = max(sum[i + ti[i]], sum[i] + pay[i]);
        }
    }
    cout << max(sum[N], sum[N + 1]);
    return 0;
}
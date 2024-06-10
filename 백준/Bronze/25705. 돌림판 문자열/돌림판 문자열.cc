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

int N, M;
string words, target;
int ans;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); std::cout.tie(NULL);
    cin >> N; cin >> words; cin >> M; cin >> target;

    int idx = N - 1;
    int turn = 0;
    int tidx = 0;

    while (1)
    {
        if (tidx == M)
            break ;
        turn++;
        idx++;
        if (idx == N)
            idx = 0;
        if (words[idx] == target[tidx]) {
            tidx++;
            ans += turn;
            turn = 0;
        }

        if (turn >= N) {
            cout << -1; return 0;
        }
    }
    cout << ans << '\n';
    return 0;
}
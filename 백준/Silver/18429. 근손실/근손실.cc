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

int N, K;
int kit[55];
int w = 500;
int ans;

int arr[10];
int isused[55];

void    spoany()
{
    for (int i = 0; i < N; i++) {
        w += kit[arr[i]];
        w -= K;
        if (w < 500)
            return ;
    }
    ans += 1;
}

void    solve(int k)
{
    if (k == N) {
        // for (int i = 0; i < N; i++) {
        //     cout << arr[i] << ' ';
        // }   cout << '\n';
        w = 500;
        spoany();
        return ;
    }  

    for (int i = 1; i <= N; i++) {
        if (!isused[i]) {
            arr[k] = i;
            isused[i] = 1;
            solve(k + 1);
            isused[i] = 0;
        }
    }

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); std::cout.tie(NULL);
    cin >> N >> K;
    for (int i = 1; i <= N; i++)
        cin >> kit[i];

    solve(0);
    cout << ans;
    return 0;
}
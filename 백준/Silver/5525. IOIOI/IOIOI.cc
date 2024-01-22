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

int N, M;
string S;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M >> S;     

    int ans = 0;
    for (int i = 0; i < M; i++) {
        int k = 0;
        if (S[i] == 'O')
            continue ;
        while (S[i + 1] == 'O' && S[i + 2] == 'I') {
            k++;
            if (k == N) {
                ans++;
                k--;
            }
            i += 2;
        }
    }
    cout << ans;
    return 0;
}
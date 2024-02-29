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

int room[12];
int ans;
int N, K;
// [1] 0 1 [2] 0 1 ...
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); std::cout.tie(NULL);
    cin>>N>>K;
    
    for (int i = 0; i < N; i++) {
        int s, g; cin>>s>>g;
        room[(g*2)-(s+1)]++;
    }
    for (int i = 0; i < 12; i++) {
        if ((room[i] % K) > 0)
            ans += (room[i] / K) + 1;
        else
            ans += (room[i] / K); 
    }
    cout << ans;
    return 0;
}
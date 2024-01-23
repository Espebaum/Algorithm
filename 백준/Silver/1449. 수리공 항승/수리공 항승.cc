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
using namespace std;

int N, L;
vector<int> v;
int arr[1010];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> L;
    for (int i = 0; i < N; i++) {
        int n; cin >> n;
        v.push_back(n);
        arr[n] = -1;
    }
    int ans = 0;
    for (int i = 1; i <= 1000; i++) {
        if (arr[i] == -1) {
            ans += 1;
            i += L - 1;
        }
    }    
    cout << ans;

    return 0;
}
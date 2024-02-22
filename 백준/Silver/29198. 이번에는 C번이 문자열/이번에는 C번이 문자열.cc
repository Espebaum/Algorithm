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

int N, M, K;
vector<pair<int,string>>vp;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M >> K;
    for (int i = 0; i < N; i++){
        string s; cin>>s;
        int num = 0;
        for (int j = 0; j < M; j++) {
            num += (int)s[j];
        }
        vp.push_back({num, s});
    }
    sort(vp.begin(), vp.end());
    // for (int i = 0; i < N; i++) {
        // cout << vp[i].first << ' ' << vp[i].second << '\n';
    // }
    string t;
    for (int i = 0; i < K; i++) {
        t += vp[i].second;
    }
    sort(t.begin(), t.end());
    cout << t;
    return 0;
}
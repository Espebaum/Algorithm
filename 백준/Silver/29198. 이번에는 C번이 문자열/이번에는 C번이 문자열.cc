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

ll N, M, K;
vector<string>vp;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M >> K;
    for (int i = 0; i < N; i++){
        string s; cin>>s; 
        sort(s.begin(), s.end());
        vp.push_back(s);
    }
    sort(vp.begin(), vp.end());
    // for (int i = 0; i < N; i++) {
    //     cout << vp[i] << '\n';
    // }
    string t;
    for (int i = 0; i < K; i++)
        t += vp[i];
    sort(t.begin(), t.end());
    cout << t;
    return 0;
}
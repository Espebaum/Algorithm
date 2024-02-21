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
//10^5 = 100000 ( 1<=N<=200000)

int N;
vector<tuple<double,double,int>>pos;
vector<tuple<double,double,int>>info; // first 기울기, second 거리

vector<pair<int,int>>line13;
vector<pair<int,int>>line24;

bool compare(tuple<double,double,int>a,tuple<double,double,int>b)
{
    if (get<0>(a) == get<0>(b))
        return get<2>(a) < get<2>(b);
    return get<0>(a) < get<0>(b);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++) {
        double x,y; cin>>x>>y;
        int sa;
        if ((x > 0 && y > 0) || (x > 0 && y == 0))
            sa = 1;
        else if ((x < 0 && y > 0) || (x == 0 && y > 0))
            sa = 2;
        else if ((x < 0 && y < 0) || (x < 0 && y == 0))
            sa = 3;
        else if ((x > 0 && y < 0) || (x == 0 && y < 0))
            sa = 4;
        pos.push_back({x, y, sa});
    } 

    for (int i = 0; i < N; i++) {
        double cx = get<0>(pos[i]);
        double cy = get<1>(pos[i]);
        int cs = get<2>(pos[i]);
        double gi = double (cy) / (cx);
        double di = sqrt(pow(cx, 2) + pow(cy, 2));
        info.push_back({gi, di, cs});
    }
    sort(info.begin(), info.end(), compare);

    int board[4];
    double cur = 1e9;
    int sa = 1e9;
    int ans = 0;
    for (int i = 0; i < info.size(); i++) {
        // cout << "기울기: " << get<0>(info[i]) << " 거리: " << get<1>(info[i]) << " 사분면: "<< get<2>(info[i]) << '\n';
        if (cur != get<0>(info[i])) {
            cur = get<0>(info[i]);
            sa = get<2>(info[i]);
            ans++;
        }
        if (cur == get<0>(info[i]) && sa != get<2>(info[i])) {
            sa = get<2>(info[i]);
            ans++;
        }
    }
    cout << ans;
    return 0;
}
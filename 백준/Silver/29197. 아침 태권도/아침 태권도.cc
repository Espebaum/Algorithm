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
vector<pair<int,int>>pos;
int board[10002][10002];
vector<pair<double,double>>info; // first 기울기, second 거리

bool compare(pair<double,double>a,pair<double,double>b)
{
    if (a.first == b.first)
        return a.second < b.second;
    return a.first < b.first;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    // 관장님은 (5000, 5000)
    int gx = 5000;
    int gy = 5000;
    for (int i = 0; i < N; i++) {
        int x,y; cin>>x>>y;
        pos.push_back({x+5000, y+5000});
        board[x+5000][y+5000] = 1;
    } 

    for (int i = 0; i < N; i++) {
        int cx = pos[i].first;
        int cy = pos[i].second;
        double gi = double (cy - gy) / (cx - gx);
        double di = sqrt(pow(cx - gx, 2) + pow(cy - gy, 2));
        info.push_back({gi, di});
    }
    sort(info.begin(), info.end(), compare);

    double cur = 1e9;
    int ans = 0;
    for (int i = 0; i < info.size(); i++) {
        // cout << "기울기: " << info[i].first << " 거리: " << info[i].second << '\n';
        if (cur != info[i].first) {
            cur = info[i].first;
            ans++;
        }
    }
    cout << ans;
    return 0;
}
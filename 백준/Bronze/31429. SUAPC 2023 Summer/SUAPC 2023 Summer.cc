#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
typedef long long ll;
const int INF = 0x3f3f3f3f;
using namespace std;

int N;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); std::cout.tie(NULL);
    cin >> N;
    vector<pair<int,int>>vp(13);
    vp[1].second = 1600;

    vp[1].first = 12;
    vp[2].first = 11;
    vp[3].first = 11;
    vp[4].first = 10;
    vp[5].first = 9;
    vp[6].first = 9;
    vp[7].first = 9;
    vp[8].first = 8;
    vp[9].first = 7;
    vp[10].first = 6;
    vp[11].first = 6;
    vp[1].second = 1600;
    vp[2].second = 894;
    vp[3].second = 1327;
    vp[4].second = 1311;
    vp[5].second = 1004;
    vp[6].second = 1178;
    vp[7].second = 1357;
    vp[8].second = 837;
    vp[9].second = 1055;
    vp[10].second = 556;
    vp[11].second = 773;

    cout << vp[N].first << ' ' << vp[N].second << '\n';

    return 0;
}
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

int T, n;
int arr[100100];
// int vis[100100];
int tp[100100];
int p[100100];

int Find(int x)
{
    if (p[x] == x) return x;
    return p[x] = Find(p[x]);
}

void    Union(int x, int y)
{
    int px = Find(x);
    int py = Find(y);
    p[py] = px;
}

void    tUnion(int x, int y)
{
    tp[y] = x;
}

int tFind(int x)
{
    if (tp[x] == x)
        return x;
    return tp[x];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); std::cout.tie(NULL);
    cin >> T;
    while (T--)
    {
        cin>>n;
        for (int i = 1; i <= n; i++) {
            p[i] = i; arr[i] = 0;
        }
        for (int i = 1; i <= n; i++) {
            int pa; cin>>pa;
            tUnion(pa, i);
            Union(pa, i);
        }
        int ans = 0;
        vector<int>rot;
        for (int i = 1; i <= n; i++) {
            if (p[i] == i)
                rot.push_back(i);
        }
        for (int i = 0; i < rot.size(); i++) {
            int rst = rot[i];
            int st = rot[i];
            while (1) {
                st = tFind(st);
                arr[st] = 1;
                if (st == rst)
                    break ;
            }
        }
        for (int i = 1; i <= n; i++) {
            if (arr[i] == 0)
                ans++;
        }
        cout << ans << '\n';
    }
    return 0;
}
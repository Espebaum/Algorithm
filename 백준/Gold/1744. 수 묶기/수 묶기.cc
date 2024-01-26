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

int N, num;
vector<int> pl;
vector<int> mi;

void    solve1()
{
    int psum = 0;
    int msum = 0;
    for (int i = pl.size() - 1; i >= 0; i -= 2){
        if (i == 0) {
            psum += pl[i];
        } else {
            if (pl[i] + pl[i - 1] < pl[i] * pl[i - 1])
                psum += pl[i] * pl[i - 1];
            else 
                psum += pl[i] + pl[i - 1];
        }
    }
    for (int i = mi.size() - 1; i >= 0; i -= 2) {
        if (i == 0) {
            msum += mi[i];
        } else {
            msum += mi[i] * mi[i - 1];
        }
    }
    cout << psum + msum;
}

bool compare(int a, int b)
{
    return a > b;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    if (N == 1) {
        cin >> num; cout << num; return 0;
    }
    for (int i = 0; i < N; i++) {
        cin >> num;
        if (num > 0)
            pl.push_back(num);
        else
            mi.push_back(num);
    }
    sort(pl.begin(), pl.end());
    sort(mi.begin(), mi.end(), compare);
    solve1();
    return 0;
}
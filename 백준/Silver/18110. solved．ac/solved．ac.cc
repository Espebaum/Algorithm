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

int n;
vector<int> v;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    if (n == 0) {
        cout << 0;
        return 0;
    }
    for (int i = 0; i < n; i++) {
        int num; cin >> num;
        v.push_back(num);
    }
    sort(v.begin(), v.end());
    double l = (double) n * 0.15;
    double rl = round(l);
    double sum = 0;
    for (int i = rl; i < v.size() - rl; i++) {
        sum += v[i];
    }
    double value = sum / (v.size() - 2*rl);
    double rv = round(value);
    cout << rv;
    return 0;
}
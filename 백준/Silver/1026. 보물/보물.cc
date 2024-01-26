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

int N;
vector<int> a;
vector<int> b;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;

    for (int i = 0; i < N; i++) {
        int num; cin >> num;
        a.push_back(num);
    }
    
    for (int i = 0; i < N; i++) {
        int num; cin >> num;
        b.push_back(num);
    }
    sort(a.begin(), a.end());

    vector<int> tb(b);
    sort(tb.begin(), tb.end(), greater<int>());

    int sum = 0;
    for (int i = 0; i < N; i++) {
        // cout << "a: " << a[i] << " tb: " << tb[i] << '\n';
        sum += a[i]*tb[i];
    }
    cout << sum;

    return 0;
}
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <deque>
#include <utility>
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
using namespace std;

int N;
vector<int> v;

int check()
{
    int tmp = N;

    while (tmp) {
        if (tmp - 3 < 0)
            break ;
        if (v[tmp - 1] - v[tmp - 2] != v[tmp - 2] - v[tmp - 3])
            return 1;
        tmp--;
    }
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++) {
        int num; cin >> num;
        v.push_back(num);
    }

    int d = check();
    // cout << "res : " << d << '\n';

    if (d) {
        int b = v[1]/v[0];
        cout << v[N - 1] * b;
    }
    else {
        int c = v[1] - v[0];
        // cout << "+ : " << c << '\n';
        cout << v[N - 1] + c;
    }

    return 0;
}
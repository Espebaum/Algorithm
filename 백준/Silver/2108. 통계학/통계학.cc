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
using namespace std;

int N;
vector<int> v;
int board[8080];

void    arith()
{
    int sum = 0;
    for (int i = 0; i < v.size(); i++) {
        sum += v[i];
    }
    int len = (int) v.size();
    double ans1 = (double)sum / len;
    if (round(ans1) == -0) {
        cout << 0 << '\n';
    } else {
        cout << round(ans1) << '\n';
    }
}

void    median()
{
    vector<int> t(v);
    sort(t.begin(), t.end());
    cout << t[t.size() / 2] << '\n';
}

void    mode()
{
    vector<int> m;
    for (int i = 0; i < v.size(); i++) {
        board[v[i]+4000]++;
    }

    int mx = 0;
    for (int i = 0; i < 8080; i++) {
        mx = max(mx, board[i]);
    }

    for (int i = 0; i < 8080; i++) {
        if (board[i] == mx)
            m.push_back(i - 4000);
    }

    if (m.size() == 1)
        cout << m[0] << '\n';
    else {
        sort(m.begin(), m.end());
        cout << m[1] << '\n';
    }
}

void    range()
{
	pair<vector<int>::iterator, vector<int>::iterator> p = minmax_element(v.begin(), v.end());
	
	int min = *(p.first);
	int max = *(p.second);
	
	cout << max - min;
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

    arith();
    median();
    mode();
    range();

    return 0;
}
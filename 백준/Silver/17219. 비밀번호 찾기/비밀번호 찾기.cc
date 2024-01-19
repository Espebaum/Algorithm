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

int N, M;
map<string, string> link;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;

    string a;
    string b;
    for (int i = 0; i < N; i++) {
        cin >> a >> b;
        link[a] = b;
    }

    for (int i = 0; i < M; i++) {
        string  s;
        cin >> s;
        cout << link[s] << '\n';
    }

    return 0;
}
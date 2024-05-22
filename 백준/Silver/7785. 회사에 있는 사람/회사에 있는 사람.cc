#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <list>
#include <utility>
#include <cmath>
#include <tuple>
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
typedef long long ll;
const int INF = 0x3f3f3f3f;
using namespace std;

int N;
set<string> workers;
string name, status;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); std::cout.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> name >> status;
        if (status == "enter")
            workers.insert(name);
        else
            workers.erase(name);
    }

    for (auto it = workers.rbegin(); it != workers.rend(); it++)
        cout << *it << '\n';

    return 0;
}
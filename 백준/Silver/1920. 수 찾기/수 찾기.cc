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
vector<int> v;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++) {
        int num; cin >> num;
        v.push_back(num);
    }
    sort(v.begin(), v.end());
    
    cin >> M;
    for (int i = 0; i < M; i++) {
        int target; cin >> target;
        int st = 0;
        int en = N - 1;
        int c = 0;
        while (st <= en)
        {
            int mid = (st + en) / 2;
            if (target < v[mid]) {
                en = mid - 1;
            } else if (target > v[mid]) {
                st = mid + 1;
            } else {
                c = 1;
                break ;
            }
        }
        cout << c << '\n';
    }

    return 0;
}
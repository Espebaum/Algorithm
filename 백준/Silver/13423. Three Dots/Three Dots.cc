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

int T;
int N;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); std::cout.tie(NULL);

    cin >> T;

    while (T--)
    {
        cin >> N;
        int ans = 0;
        vector<int>dots(N);
        for (int i = 0; i < N; i++)
            cin >> dots[i];
        sort(dots.begin(), dots.end());
        for (int i = 0; i < N - 2; i++) { // N-2
            for (int j = i + 1; j < N - 1; j++) {
                int target = dots[j] * 2 - dots[i];
                int st = j + 1;
                int en = N - 1;
                while (st <= en)
                {
                    int mid = st + (en - st) / 2;
                    if (dots[mid] == target) {
                        ans += 1; 
                        break ;
                    }
                    if (dots[mid] < target)
                        st = mid + 1;
                    else if (dots[mid] > target) 
                        en = mid - 1;
                }
            } 
        }
        cout << ans << '\n';
    }
    return 0;
}
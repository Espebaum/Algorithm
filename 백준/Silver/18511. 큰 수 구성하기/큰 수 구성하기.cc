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
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
using namespace std;

int N, K, num;
vector<int> v;
int ans;


void    dfs(int num, int sum)
{
    if (num > N)
        return ;
    
    ans = max(ans, num);

    for (int i = 0; i < K; i++)
    {
        dfs(num + sum * v[i], sum * 10);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> K;
    for (int i = 0; i < K; i++) {
        cin >> num;
        v.push_back(num);
    }
    sort(v.begin(), v.end());
    dfs(0, 1);
    cout << ans << '\n';
    return 0;
}
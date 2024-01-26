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

int N, S;
int arr[30];
int cnt = 0;

void    func(int cur, int sum) {
    if (cur == N) {
        if (sum == S) 
            cnt++;
        return ;
    }
    func(cur + 1, sum);
    func(cur + 1, sum + arr[cur]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> S;

    for (int i = 0; i < N ; i++)
        cin >> arr[i];

    func(0, 0);
    if (S == 0)
        cnt--;
    cout << cnt;

    return 0;
}
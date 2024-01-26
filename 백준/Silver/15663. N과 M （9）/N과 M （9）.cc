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

int N, M;
int arr[10];
int isused[10];
vector<int> v;

// 1 7 9 9
void    solve(int k)
{
    if (k == M) {
        for (int i = 0; i < M; i++)
            cout << arr[i] << ' ';
        cout << '\n';
        return ;
    }
    
    int tmp = 0;
    for (int i = 0; i < N; i++) {
        if (!isused[i] && tmp != v[i]) {
            arr[k] = v[i];
            isused[i] = 1;
            tmp = arr[k];
            solve(k + 1);
            isused[i] = 0;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        int num; cin >> num;
        v.push_back(num);
    }

    sort(v.begin(), v.end());
    solve(0);

    return 0;
}
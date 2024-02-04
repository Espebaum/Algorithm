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

int N,v;
int arr[110];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    cin >> v;
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        if (arr[i] == v)
            cnt++;
    }
    cout << cnt;
    return 0;
}
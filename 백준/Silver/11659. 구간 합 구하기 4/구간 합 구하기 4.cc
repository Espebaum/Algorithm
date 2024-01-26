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
int arr[100010];
int sum[101010];


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }

    sum[1] = arr[1];

    for (int i = 2; i <= N; i++) {
        sum[i] = sum[i - 1] + arr[i];
    }

    int a, b;
    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        cout << sum[b] - sum[a - 1] << '\n';
    }

    return 0; 
}
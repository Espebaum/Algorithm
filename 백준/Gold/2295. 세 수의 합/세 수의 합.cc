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

int N;
int arr[1010];
int two[1000010];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + N);
    int idx = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i; j < N; j++) {
            two[idx] = arr[i] + arr[j];
            idx++;
        }
    }
    sort(two, two+idx);

    for (int i = N - 1; i > 0; i--) {
        for (int j = 0; j <= i; j++) {
            if (binary_search(two, two+idx, arr[i]-arr[j])) {
                cout << arr[i];
                return 0;
            }
        }
    }

    return 0;
}
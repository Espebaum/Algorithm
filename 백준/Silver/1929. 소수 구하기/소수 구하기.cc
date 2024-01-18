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

int M, N;
bool    arr[1000001];

void set_eratos(int n) {
    for (int i = 2; i <= int(sqrt(n)); ++i) {
        if (arr[i] == 0) {
            for (int j = i * i; j <= n; j += i) { 
               
                arr[j] = 1;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> M >> N;
    arr[0] = 1;
    arr[1] = 1;

    set_eratos(N);
    for (int i = M; i <= N; i++) {
        if (arr[i] == 0)
            cout << i << '\n';
    }

    return 0;
}
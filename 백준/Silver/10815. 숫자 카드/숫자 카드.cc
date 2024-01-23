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
using namespace std;

int N, M;
int board[500005];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++) {
        int num; cin >> num;
        board[i] = num; 
    }
    sort(board, board+N);

    cin >> M;
    for (int i = 0; i < M; i++) {
        int num; cin >> num;
        cout << binary_search(board, board+N, num) << ' ';
    }

    return 0;
}
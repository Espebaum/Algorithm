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
int sum;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    
    int row = N;
    int col = M;

    int piece = 0;

    while (row > 1) {
        sum++;
        piece++;
        row--;
    }

    for (int i = 0; i < piece + 1; i++) {
        for (int j = 0; j < col - 1; j++) 
            sum++;
    }

    cout << sum << '\n';
    return 0;
}
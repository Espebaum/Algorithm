#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <list>
#include <cmath>
#include <utility>
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
using namespace std;

int board[1100][1100];
int N;
vector<int> fin;

int func(int r, int c, int N)
{
    if (N == 1) {
        return board[r][c];
    }
    
    vector<int> v;

    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            v.push_back(func(r + (i * N) / 2, c + (j * N) / 2, N / 2));
    
    sort(v.begin(), v.end());
    return v[1];
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> board[i][j];

    cout << func(0, 0, N);

    return 0;
}
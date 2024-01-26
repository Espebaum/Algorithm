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

int M;
int arr[4];

void    swap(int x, int y)
{
    int c1;
    for (int i = 0; i < 4; i++) {
        if (arr[i] == x)
            c1 = i;
    }

    int c2;
    for (int i = 0; i < 4; i++) {
        if (arr[i] == y)
            c2 = i;
    }

    int tmp = arr[c1];
    arr[c1] = arr[c2];
    arr[c2] = tmp;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> M;

    for (int i = 0; i < 4; i++)
        arr[i] = i;
    
    for (int i = 0; i < M; i++) {
        int X, Y;
        cin >> X >> Y;
        swap(X, Y);
    }

    cout << arr[1];

    return 0;
}
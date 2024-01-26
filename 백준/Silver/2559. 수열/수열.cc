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

int N, K;
int arr[101010];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>N; cin>>K;

    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;
        arr[i] = num;
    }

    int start = 0;
    int end = start + K;
    int sum = 0;
    int max = 0;

    for (int i = start; i < end; i++)
    {
        max += arr[i];
    }

    int tmp = max;
    for (int i = 0; i < N - K; i++)
    {
        tmp -= arr[start + i];
        tmp += arr[end + i];
    
        if (tmp > max)
            max = tmp;
    }
    cout << max;
    return 0;
}
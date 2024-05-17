#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
typedef long long ll;
const int INF = 0x3f3f3f3f;
using namespace std;

int N;
int arr[101010];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); std::cout.tie(NULL);

    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> arr[i];
    sort(arr+1, arr+N+1);
    int start = 1; int end = N;
    int first, second;
    int mn = 2147483647;

    while (start < end)
    {
        int temp = mn;
        int result = abs(arr[start] + arr[end]);
        mn = min(result, mn);
        if (mn != temp) {
            first = arr[start];
            second = arr[end];
        }
        if (arr[start] + arr[end] < 0)
            start += 1;
        else if (arr[start] + arr[end] == 0)
            break ;
        else
            end -= 1;
    }
    cout << first << ' ' << second << '\n';

    return 0;
}
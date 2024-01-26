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

int N;
int num;
int strike;
int ball;
bool    arr[1000];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    for (int i = 123; i <= 987; i++) {
        arr[i] = true;
    }

    cin >> N;
    for (int i = 123; i <= 987; i++) {
        string s = to_string(i);

        if (s[0] == s[1] || s[1] == s[2] || s[0] == s[2])
            arr[i] = false;
        if ((int)s[0] == 48 || (int)s[1] == 48 || (int)s[2] == 48)
            arr[i] = false;
    }

    while (N--) {
        cin >> num >> strike >> ball;
        for (int i = 123; i <= 987; i++) {
            int st = 0;
            int bl = 0;
            if (arr[i] == true) {
                string  input = to_string(num);
                string  compare = to_string(i);

                for (int j = 0; j < 3; j++) {
                    for (int k = 0; k < 3; k++) {
                        if (j == k && input[j] == compare[k])
                            st++;
                        if (j != k && input[j] == compare[k])
                            bl++;
                    }
                }
                if (st != strike || bl != ball)
                    arr[i] = false;
            }
        }
    }
    int cnt = 0;
    for (int i = 123; i <= 987; i++) {
        if (arr[i] == true)
            cnt++;
    }
    cout << cnt;

    return 0;
}
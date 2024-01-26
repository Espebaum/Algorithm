#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <list>
#include <map>
#include <utility>
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
using namespace std;

string  s;
int     tc;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> s;
    cin >> tc;
    list<char> l;
    for (int i = 0; i < s.length(); i++) {
        l.push_back(s[i]);
    }
    list<char>::iterator cursor = l.end(); // a b c d (cur)

    while (tc--) {
        char    c;
        cin >> c;
        if (c == 'P') {
            char    w;
            cin >> w;
            l.insert(cursor, w);
        }
        else if (c == 'L') {
            if (cursor != l.begin())
                cursor--;
        }
        else if (c == 'D') {
            if (cursor != l.end())
                cursor++;
        }
        else if (c == 'B') {
            if (cursor != l.begin()) {
                cursor--;
                cursor = l.erase(cursor);
            }
        }
    }

    for (list<char>::iterator iter = l.begin(); iter != l.end(); iter++) {
        cout << *iter;
    }

    return 0;
}
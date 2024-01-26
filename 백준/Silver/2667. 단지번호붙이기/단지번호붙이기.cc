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
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int board[30][30];
int vis[30][30];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < N; j++)
            board[i][j] = s[j] - '0';
    }

    queue< pair<int, int> > q;

    int dan = 0;
    vector<int> v;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (board[i][j] == 1 && !vis[i][j])
            {
                dan++;
                vis[i][j] = 1;
                int area = 1;
                q.push(make_pair(i, j));
                while (!q.empty())
                {       
                    pair<int, int> cur = q.front(); q.pop();
                    for (int dir = 0; dir < 4; dir++)
                    {
                        int nx = cur.first + dx[dir];
                        int ny = cur.second + dy[dir];
                        if (nx < 0 || nx >= N || ny < 0 || ny >= N)
                            continue;
                        if (vis[nx][ny] || board[nx][ny] == 0)
                            continue;
                        vis[nx][ny] = 1;
                        area++;
                        q.push(make_pair(nx, ny));
                    }
                }
                v.push_back(area);
            }
        }
    }
    sort(v.begin(), v.end());
    cout << dan << '\n';
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << '\n';

    return 0;
}
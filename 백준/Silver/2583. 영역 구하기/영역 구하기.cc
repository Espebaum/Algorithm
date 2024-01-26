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

int M, N, K;
int board[101][101];
int vis[101][101];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin>>M>>N>>K;

    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++)
            board[i][j] = 1;

    for (int i = 0; i < K; i++)
    {
        int x1, y1, x2, y2;
        cin>>y1>>x1>>y2>>x2;
        for (int j = x1; j < x2; j++)
            for (int k = y1; k < y2; k++)
                board[j][k] = 0;
    }

    queue< pair<int, int> > q;
    vector<int> v;
    int ans = 0;

    for (int i = 0; i < M; i++) 
    {
        for (int j = 0; j < N; j++) 
        {
            if (board[i][j] == 1 && !vis[i][j])
            {
                ans++;
                vis[i][j] = 1;
                int area = 1;
                q.push(make_pair(i, j));
                while (!q.empty())
                {
                    pair<int, int> cur = q.front(); 
                    q.pop();
                    for (int dir = 0; dir < 4; dir++)
                    {
                        int nx = cur.first + dx[dir];
                        int ny = cur.second + dy[dir];
                        if (nx < 0 || nx >= M || ny < 0 || ny >= N)
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
    cout << ans << endl;
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << ' ';
    return 0;
}
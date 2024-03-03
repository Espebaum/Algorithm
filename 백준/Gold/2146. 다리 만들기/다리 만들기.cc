#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
const int INF = 0x3f3f3f3f;
using namespace std;

int N;
int board[110][110];
int vis[110][110];
int dist[110][110];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
map<pair<int,int>,int>land;
vector<int>dists;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin>>N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }

    queue<pair<int,int>>q;
    int area = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j] && !vis[i][j]) {
                area += 1;
                vis[i][j] = 1;
                q.push({i, j});
                land[{i,j}] = area;
                while (!q.empty()) {
                    pair<int,int>cur = q.front(); q.pop();
                    int cx = cur.first; int cy = cur.second;
                    for (int dir = 0; dir < 4; dir++) {
                        int nx = cx + dx[dir];
                        int ny = cy + dy[dir];
                        if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
                        if (!board[nx][ny] || vis[nx][ny])
                            continue;
                        vis[nx][ny] = 1;
                        land[{nx, ny}] = area;
                        q.push({nx, ny});
                    }
                }
            }
        }
    }

    for (auto e: land) {
        int point = 0;
        int cx = e.first.first;
        int cy = e.first.second;
        int ca = e.second;
        for (int dir = 0; dir < 4; dir++) {
            int nx = cx + dx[dir];
            int ny = cy + dy[dir];
            if (nx < 0 || nx >= N || ny < 0 || ny >= N)
                continue;
            if (!board[nx][ny]) 
                point++;
        }
        if (point > 0) {
            for (int j = 0; j < N; j++)
                fill(dist[j], dist[j] + N, -1);
            dist[cx][cy] = 0;
            q.push({cx, cy});
            while (!q.empty()) {
                pair<int,int>cur = q.front(); q.pop();
                for (int dir = 0; dir < 4; dir++) {
                    int nx = cur.first + dx[dir];
                    int ny = cur.second + dy[dir];
                    if (nx < 0 || nx >= N || ny < 0 || ny >= N)
                        continue;
                    if (dist[nx][ny] != -1)
                        continue ;
                    if (!board[nx][ny]) {
                        dist[nx][ny] = dist[cur.first][cur.second] + 1;
                        q.push({nx, ny});
                    }
                    else {
                        pair<int,int> key = make_pair(nx, ny);
                        auto it = land.find(key);
                        if (it != land.end()) {
                            if (it->second != ca) {
                                dists.push_back(dist[cur.first][cur.second]);
                                while (!q.empty())
                                    q.pop();
                            }
                        }
                    }
                }
            }
        }
    }
    sort(dists.begin(), dists.end());
    cout << dists[0];
    return 0;
}
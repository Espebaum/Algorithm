#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
const int INF = 0x3f3f3f3f;
using namespace std;

int N;
int board[25][25];
int dist[25][25];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
vector<tuple<int,int,int>>vt;

bool compare(tuple<int,int,int>a, tuple<int,int,int>b)
{
    if (get<0>(a) != get<0>(b)) 
        return get<0>(a) < get<0>(b);
    if (get<1>(a) != get<1>(b)) 
        return get<1>(a) < get<1>(b);
    return get<2>(a) < get<2>(b);

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>N;
    int sx, sy, size, point;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
            if (board[i][j] == 9) {
                sx = i; sy = j; size = 2; point = 0;
            }
        }
    }
    int sec = 0;
    while (1)
    {
        for (int i = 0; i < N+1; i++)
            fill(dist[i], dist[i]+N+1, -1);
        queue<pair<int,int>>q;
        q.push({sx, sy});
        dist[sx][sy] = 0;
        board[sx][sy] = 0;
        while (!q.empty())
        {
            pair<int,int>cur=q.front();q.pop();
            int cx = cur.first; int cy = cur.second;
            for (int dir = 0; dir < 4; dir++) {
                int nx = cx+dx[dir];
                int ny = cy+dy[dir];
                if (nx < 0 || nx >= N || ny < 0 || ny >= N)
                    continue;
                if (dist[nx][ny] != -1 || board[nx][ny] > size)
                    continue;
                dist[nx][ny] = dist[cx][cy]+1;
                if (board[nx][ny] > 0 && board[nx][ny] < size)
                    vt.push_back({dist[nx][ny],nx,ny});
                q.push({nx,ny});
            }
        }        
        if (vt.empty()) {
            cout << sec;
            return 0;
        } else {
            sort(vt.begin(), vt.end(), compare);
            sx = get<1>(vt[0]);
            sy = get<2>(vt[0]);
            board[sx][sy] = 0;
            point += 1;
            if (point == size) {
                size += 1;
                point = 0;
            }
        }
        sec += dist[sx][sy];
        vt.clear();
    }
    cout << sec;
    return 0;
}
#include <bits/stdc++.h>
typedef long long ll;
const int INF = 0x3f3f3f3f;
using namespace std;

string  board[15];
vector<pair<int,int>>coor;
queue<pair<int,int>>q;
int vis[15][15];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int arr[128];
int ans;

int getCoor()
{
    for (int i = 0; i < 12; i++)
        fill(vis[i], vis[i]+6, 0);
    char curC;
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < board[i].length(); j++) {
            if (board[i][j] != '.' && !vis[i][j]) {
                curC = (char) board[i][j];
                if (arr[curC] == 0)
                    coor.push_back({i, j});
                arr[curC]++;
                vis[i][j] = 1;
                q.push({i, j});
                while (!q.empty()) {
                    pair<int,int>cur = q.front(); q.pop();
                    for (int dir = 0; dir < 4; dir++) {
                        int nx = cur.first + dx[dir];
                        int ny = cur.second + dy[dir];
                        if (nx < 0 || nx > 11 || ny < 0 || ny > 6)
                            continue ;
                        if ((char)board[nx][ny] != curC || vis[nx][ny])
                            continue;
                        vis[nx][ny] = 1;
                        q.push({nx, ny});
                    }
                }
            }
            arr[curC] = 0;
        }
    }
    if (coor.empty())
        return 0;
    return 1;
}

void    falldown()
{
    for (int j = 0; j < 6; j++) {
        int pos = 0;
        int fixed = 0;
        for (int i = 0; i < 12; i++) {
            if (board[i][j] == '.' && !fixed) {
                pos = i; fixed = 1;
            }
            else if (board[i][j] != '.' && fixed == 1) {
                char c = board[i][j];
                int temp = i;
                board[pos][j] = c;
                board[i][j] = '.';
                i = pos;
                fixed = 0;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); std::cout.tie(NULL);

    for (int i = 11; i >= 0; i--) {
        string s; cin >> s;
        board[i] = s;
    }

    while (getCoor() == 1)
    {
        bool isBroken = false;
        for (int i = 0; i < 12; i++)
            fill(vis[i], vis[i]+6, 0);
        int point;
        char curC;
        vector<pair<int,int>>toErase;
        for (int i = 0; i < coor.size(); i++) {
            pair<int,int>cur = make_pair(coor[i].first, coor[i].second);
            q.push({cur.first, cur.second});
            curC = board[coor[i].first][coor[i].second];
            vis[coor[i].first][coor[i].second] = 1;
            point = 1;
            while (!q.empty()) {
                pair<int,int>curP = q.front(); q.pop();
                toErase.push_back({curP.first, curP.second});
                for (int dir = 0; dir < 4; dir++) {
                    int nx = curP.first + dx[dir];
                    int ny = curP.second + dy[dir];
                    if (nx < 0 || nx > 11 || ny < 0 || ny > 6)
                        continue;
                    if ((char)board[nx][ny] != curC || vis[nx][ny])
                        continue;
                    toErase.push_back({nx, ny});
                    point++;
                    vis[nx][ny] = 1;
                    q.push({nx,ny});
                }
            }
            if (point >= 4) {
                isBroken = true;
                for (int i = 0; i < toErase.size(); i++)
                    board[toErase[i].first][toErase[i].second] = '.';
            }
            toErase.clear();
        }
        falldown();

        if (isBroken)
            ans++;
        else
            break ;
        coor.clear();
    }

    cout << ans;

    return 0;
}
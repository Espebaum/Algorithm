#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <deque>
#include <utility>
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define X first
#define Y second
//define 뒤에는 세미콜론을 붙히지 말자
using namespace std;

string	board[102];
int		dis[102][102]; 
//vis 배열의 합이 그 타일까지의 거리라는 것을 착안해 만들어진 거리 배열
int 	dx[4] = {1, 0, -1, 0};
int 	dy[4] = {0, 1, 0, -1};
int		r, c;
queue<pair<int, int>> q;

void	bfs(int x, int y)
{
	dis[x][y] = 1; // 미로는 항상 0,0에서 시작, 시작 타일도 치므로 거리 1
	q.push({x, y});
	while (!q.empty())
	{
		pair<int, int> cur = q.front(); q.pop();
		for (int dir = 0; dir < 4; dir++)
		{
			int nx = cur.X + dx[dir];
			int	ny = cur.Y + dy[dir];
			if (nx < 0 || nx >= r || ny < 0 || ny >= c) 
				continue;
			if (dis[nx][ny] || board[nx][ny] != '1')
				continue;
			// cout<<nx<<ny<<dis[nx][ny]<<'\n';
			dis[nx][ny] = dis[cur.X][cur.Y] + 1;
			q.push({nx, ny});
		}
	}
	cout<<dis[r - 1][c - 1];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin>>r>>c;
	for (int i = 0; i < r; i++)
			cin>>board[i];
	bfs(0, 0);
	return 0;
}
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

//건물층 F, 현재층 S, 스타트링크층 G, 위로 U칸, 아래로 D칸 
int F, S, G, U, D;
int dist[1000002];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>F>>S>>G>>U>>D;
    
    fill(dist, dist + F + 1, -1);
    queue<int> q;
    dist[S] = 0;
    q.push(S);

    while(!q.empty())
    {
        int cur = q.front(); q.pop();
        for (int dir = 0; dir < 2; dir++)
        {
            int newcur;
            if (dir == 0)
                newcur = cur + U;
            else
                newcur = cur - D;
            if (newcur < 1 || newcur > F || dist[newcur] >= 0)
                continue;
            dist[newcur] = dist[cur] + 1;
            q.push(newcur);
        }
    }
    if (dist[G] != -1)
        cout << dist[G];
    else   
        cout << "use the stairs";
    return 0;
}
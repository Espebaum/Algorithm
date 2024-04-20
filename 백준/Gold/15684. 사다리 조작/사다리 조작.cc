#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
const int INF = 0x3f3f3f3f;
using namespace std;

int board[400][20];
int N, M, H;
vector<pair<int,int>>zone;

bool    down()
{
    for (int i = 1; i <= N; i++) 
    {
        pair<int,int>st = {1, i};
        int ob = st.second;
        for (int j = 1; j <= H; j++) {
            if (board[st.first][st.second] != 0)
                st.second = board[st.first][st.second];
            st.first += 1;
        }
        if (st.second != ob)
            return false;
    }
    return true;
}

bool    solve3() 
{
    for (int i = 0; i < zone.size() - 2; i++) {
        for (int j = i + 1; j < zone.size() - 1; j++) {
            for (int k = j + 1; k < zone.size(); k++) {
                pair<int,int>cur1 = zone[i];
                pair<int,int>cur2 = zone[j];
                pair<int,int>cur3 = zone[k];
                int x1 = cur1.first; int y1 = cur1.second;
                int x2 = cur2.first; int y2 = cur2.second;
                int x3 = cur3.first; int y3 = cur3.second;
                if ((x1 == x2 && (y1 - y2) == -1) || (x2 == x3 && (y2 - y3) == -1) || (x1 == x3 && (y1 - y3) == -1))
                    continue;
                board[x1][y1] = y1 + 1; board[x1][y1 + 1] = y1;
                board[x2][y2] = y2 + 1; board[x2][y2 + 1] = y2;
                board[x3][y3] = y3 + 1; board[x3][y3 + 1] = y3;
                if (down())
                    return true;
                board[x1][y1] = 0; board[x1][y1 + 1] = 0;
                board[x2][y2] = 0; board[x2][y2 + 1] = 0;
                board[x3][y3] = 0; board[x3][y3 + 1] = 0;
            }
        }
    }
    return false;
}

bool    solve2()
{
    for (int i = 0; i < zone.size() - 1; i++) {
        for (int j = i + 1; j < zone.size(); j++) {
            pair<int,int>cur1 = zone[i];
            pair<int,int>cur2 = zone[j];
            int x1 = cur1.first; int y1 = cur1.second;
            int x2 = cur2.first; int y2 = cur2.second;
            if (x1 == x2 && ((y1 - y2) == -1))
                continue;
            board[x1][y1] = y1 + 1; board[x1][y1 + 1] = y1;
            board[x2][y2] = y2 + 1; board[x2][y2 + 1] = y2;
            if (down())
                return true;
            board[x1][y1] = 0; board[x1][y1 + 1] = 0;
            board[x2][y2] = 0; board[x2][y2 + 1] = 0;
        }
    }
    return false;
}

bool    solve1()
{
    for (int i = 0; i < zone.size(); i++) {
        pair<int,int>cur = zone[i];
        int x = cur.first; int y = cur.second;
        board[x][y] = y + 1; board[x][y + 1] = y;
        if (down())
            return true;
        board[x][y] = 0; board[x][y + 1] = 0;
    }
    return false;
}

bool    solve0() 
{
    if (down()) return true;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> M >> H;
    for (int i = 0; i < M; i++) {
        int a, b; cin >> a >> b;
        board[a][b] = b + 1;
        board[a][b + 1] = b; 
    }

    for (int i = 1; i < N; i++)
        for (int j = 1; j <= H; j++)
            if (board[j][i] == 0 && board[j][i + 1] == 0)
                zone.push_back({j, i});
    
    if (zone.size() == 0) 
    {
        if (down()) 
            cout << 0;
        else
            cout << -1;
        return 0;
    }

    if (zone.size() >= 0) 
    {
        if (solve0()) 
        {
            cout << 0; 
            return 0;
        }
    }
    
    if (zone.size() >= 1) 
    {
        if (solve1()) 
        {
            cout << 1; 
            return 0;
        }
    }    

    if (zone.size() >= 2) 
    {
        if (solve2()) 
        {
            cout << 2; 
            return 0;
        }
    }

    if (zone.size() >= 3) 
    {
        if (solve3())
        { 
            cout << 3; 
            return 0;
        }
    }

    cout << -1;

    return 0;
}
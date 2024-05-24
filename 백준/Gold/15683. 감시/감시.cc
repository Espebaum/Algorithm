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
#include <cmath>
#include <tuple>
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
typedef long long ll;
const int INF = 0x3f3f3f3f;
using namespace std;

int N, M;
int arr[8];
int board[10][10];
int temp[10][10];
vector<tuple<int,int,int>>vt;
int len;
int mx = 2107483647;

void    seeType1(int k)
{
    int cx = get<0>(vt[k]);
    int cy = get<1>(vt[k]);
    // y += 1;
    if (arr[k] == 0) {
        while (1) {
            cy++;
            if (cy >= M || temp[cx][cy] == 6)
                break ;
            if (temp[cx][cy] == 0)
                temp[cx][cy] = 7;
        }
    }
    // x += 1;
    else if (arr[k] == 1) {
        while (1) {
            cx++;
            if (cx >= N || temp[cx][cy] == 6)
                break ;
            if (temp[cx][cy] == 0)
                temp[cx][cy] = 7;
        }
    } 
    // y -= 1;
    else if (arr[k] == 2) {
        while (1) {
            cy--;
            if (cy < 0 || temp[cx][cy] == 6)
                break ;
            if (temp[cx][cy] == 0)
                temp[cx][cy] = 7;
        }
    }
    // x -= 1;
    else if (arr[k] == 3) {
        while (1) {
            cx--;
            if (cx < 0 || temp[cx][cy] == 6)
                break ;
            if (temp[cx][cy] == 0)
                temp[cx][cy] = 7;
        }
    }
}

void    seeType2(int k)
{
    int cx = get<0>(vt[k]);
    int cy = get<1>(vt[k]);
    // y += 1, y -= 1;
    if (arr[k] == 0) {
        int cy1 = cy; int cy2 = cy;
        while (1) {
            cy1++;
            if (cy1 >= M || temp[cx][cy1] == 6)
                break ;
            if (temp[cx][cy1] == 0)
                temp[cx][cy1] = 8;
        }
        while (1) {
            cy2--;
            if (cy2 < 0 || temp[cx][cy2] == 6)
                break ;
            if (temp[cx][cy2] == 0)
                temp[cx][cy2] = 8;
        }
    }
    // x += 1, x -= 1;
    else if (arr[k] == 1) {
        int cx1 = cx; int cx2 = cx;
        while (1) {
            cx1++;
            if (cx1 >= N || temp[cx1][cy] == 6)
                break ;
            if (temp[cx1][cy] == 0)
                temp[cx1][cy] = 8;
        }
        while (1) {
            cx2--;
            if (cx2 < 0 || temp[cx2][cy] == 6)
                break ;
            if (temp[cx2][cy] == 0)
                temp[cx2][cy] = 8;
        }
    } 
}

void    seeType3(int k) 
{
    int cx = get<0>(vt[k]);
    int cy = get<1>(vt[k]);
    // x -= 1, y += 1;
    if (arr[k] == 0) {
        while (1) {
            cx--;
            if (cx < 0 || temp[cx][cy] == 6)
                break ;
            if (temp[cx][cy] == 0)
             temp[cx][cy] = 9;
        }
        cx = get<0>(vt[k]);
        while (1) {
            cy++;
            if (cy >= M || temp[cx][cy] == 6)
                break ;
            if (temp[cx][cy] == 0)
                temp[cx][cy] = 9;
        }
    }
    // x += 1, y += 1;
    else if (arr[k] == 1) {
        while (1) {
            cx++;
            if (cx >= N || temp[cx][cy] == 6)
                break ;
            if (temp[cx][cy] == 0)
                temp[cx][cy] = 9;
        }
        cx = get<0>(vt[k]);
        while (1) {
            cy++;
            if (cy >= M || temp[cx][cy] == 6)
                break ;
            if (temp[cx][cy] == 0)
                temp[cx][cy] = 9;
        }
    }
    // x += 1, y -= 1;
    else if (arr[k] == 2) {
        while (1) {
            cx++;
            if (cx >= N || temp[cx][cy] == 6)
                break ;
            if (temp[cx][cy] == 0)
                temp[cx][cy] = 9;
        }
        cx = get<0>(vt[k]);
        while (1) {
            cy--;
            if (cy < 0 || temp[cx][cy] == 6)
                break ;
            if (temp[cx][cy] == 0)
                temp[cx][cy] = 9;
        }
    }
    // x -= 1, y -= 1;
    else if (arr[k] == 3) {
        while (1) {
            cx--;
            if (cx < 0 || temp[cx][cy] == 6)
                break ;
             if (temp[cx][cy] == 0)
                temp[cx][cy] = 9;
        }
        cx = get<0>(vt[k]);
        while (1) {
            cy--;
            if (cy < 0 || temp[cx][cy] == 6)
                break ;
            if (temp[cx][cy] == 0)
                temp[cx][cy] = 9;
        }
    }  
}

void    seeType4(int k)
{
    int cx = get<0>(vt[k]);
    int cy = get<1>(vt[k]);
    // x -= 1, y += 1, y -= 1;
    if (arr[k] == 0) {
        int cy1 = cy; int cy2 = cy;
        while (1) {
            cy1++;
            if (cy1 >= M || temp[cx][cy1] == 6)
                break ;
            if (temp[cx][cy1] == 0)
                temp[cx][cy1] = 10;
        }
        while (1) {
            cy2--;
            if (cy2 < 0 || temp[cx][cy2] == 6)
                break ;
            if (temp[cx][cy2] == 0)
                temp[cx][cy2] = 10;
        }
        while (1) {
            cx--;
            if (cx < 0 || temp[cx][cy] == 6)
                break ;
            if (temp[cx][cy] == 0)
                temp[cx][cy] = 10;
        }
    }
    // x += 1, x -= 1, y += 1;
    else if (arr[k] == 1) {
        int cx1 = cx; int cx2 = cx;
        while (1) {
            cx1++;
            if (cx1 >= N || temp[cx1][cy] == 6)
                break ;
            if (temp[cx1][cy] == 0) 
                temp[cx1][cy] = 10;
        }
        while (1) {
            cx2--;
            if (cx2 < 0 || temp[cx2][cy] == 6)
                break ;
            if (temp[cx2][cy] == 0)
                temp[cx2][cy] = 10;
        }
        while (1) {
            cy++;
            if (cy >= M || temp[cx][cy] == 6)
                break ;
            if (temp[cx][cy] == 0)
                temp[cx][cy] = 10;
        }
    }
    // x += 1, y += 1, y -= 1;
    else if (arr[k] == 2) {
        int cy1 = cy; 
        int cy2 = cy;
        cx = get<0>(vt[k]);
        while (1) {
            cy1++;
            if (cy1 >= M || temp[cx][cy1] == 6)
                break ;
            if (temp[cx][cy1] == 0) 
                temp[cx][cy1] = 10;
        }
        while (1) {
            cy2--;
            if (cy2 < 0 || temp[cx][cy2] == 6)
                break ;
            if (temp[cx][cy2] == 0)
                temp[cx][cy2] = 10;
        }
        while (1) {
            cx++;
            if (cx >= N || temp[cx][cy] == 6)
                break ;
            if (temp[cx][cy] == 0)
                temp[cx][cy] = 10;
        }
    }
    // x += 1, x -= 1, y -= 1;
    else if (arr[k] == 3) {
        int cx1 = cx; int cx2 = cx;
        while (1) {
            cx1++;
            if (cx1 >= N || temp[cx1][cy] == 6)
                break ;
            if (temp[cx1][cy] == 0)
                temp[cx1][cy] = 10;
        }
        while (1) {
            cx2--;
            if (cx2 < 0 || temp[cx2][cy] == 6)
                break ;
            if (temp[cx2][cy] == 0) 
                temp[cx2][cy] = 10;
        }
        while (1) {
            cy--;
            if (cy < 0 || temp[cx][cy] == 6)
                break ;
            if (temp[cx][cy] == 0) 
                temp[cx][cy] = 10;
        }
    }  
}

void    seeType5(int k)
{
    int cx = get<0>(vt[k]);
    int cy = get<1>(vt[k]);
    int cx1 = cx; 
    int cx2 = cx;
    int cy1 = cy; 
    int cy2 = cy;

    while (1) {
        cx1++;
        if (cx1 >= N || temp[cx1][cy] == 6)
            break ;
        if (temp[cx1][cy] == 0)
            temp[cx1][cy] = 11;
    }
    while (1) {
        cx2--;
        if (cx2 < 0 || temp[cx2][cy] == 6)
            break ;
        if (temp[cx2][cy] == 0) {
            temp[cx2][cy] = 11;
        }
    }
    while (1) {
        cy1++;
        if (cy1 >= M || temp[cx][cy1] == 6)
            break ;
        if (temp[cx][cy1] == 0)
            temp[cx][cy1] = 11;
    }
    while (1) {
        cy2--;
        if (cy2 < 0 || temp[cx][cy2] == 6)
            break ;
        if (temp[cx][cy2] == 0)
            temp[cx][cy2] = 11;
    }
}

void    watch()
{
    for (int i = 0; i < len; i++) {
        int type = get<2>(vt[i]);
        if (type == 1)
            seeType1(i);
        else if (type == 2)
            seeType2(i);
        else if (type == 3)
            seeType3(i);
        else if (type == 4)
            seeType4(i);
        else if (type == 5)
            seeType5(i);
    }

    int count = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (temp[i][j] == 0)
                count += 1;
        }   
    }
    mx = min(mx, count);
    // if (count == 4) {
    //     cout << "count: " << count << "\n";
    //     for (int i = 0; i < N; i++) {
    //         for (int j = 0; j < M; j++) {
    //             cout << temp[i][j] << ' ';
    //         }   
    //         cout << '\n';
    //     }
    // }
}

void    solve(int k)
{
    if (k == len) {
        // cout << "ARR\n";
        // for (int i = 0; i < len; i++) {
        //     cout << arr[i] << ' ';
        // }   cout << "\n\n";
        watch();
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                temp[i][j] = board[i][j];
            }
        }
        return ;
    }

    int type = get<2>(vt[k]);
    if (type == 1 || type == 3 || type == 4) {
        for (int i = 0; i < 4; i++) {
            arr[k] = i;
            solve(k + 1);
        }
    }
    else if (type == 2) {
        for (int i = 0; i < 2; i++) {
            arr[k] = i;
            solve(k + 1);
        }
    }
    else if (type == 5) {
        arr[k] = 0;
        solve(k + 1);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); std::cout.tie(NULL);
    cin >> N >> M; 
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int type; cin >> type;
            board[i][j] = type; temp[i][j] = type;
            if (type >= 1 && type <= 5)
                vt.push_back({i, j, type});
        }
    }

    len = vt.size();
    solve(0);
    cout << mx;

    return 0;
}
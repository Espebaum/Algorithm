#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
const int INF = 0x3f3f3f3f;
using namespace std;

string  g1,g2,g3,g4;
bool r12, r23, r34;
int T;

void    rel(int left, int right)
{
    if (left == 1 && right == 2) {
        if (g1[2] != g2[6])
            r12 = true;
        else
            r12 = false;
    }

    if (left == 2 && right == 3) {
        if (g2[2] != g3[6])
            r23 = true;
        else
            r23 = false;
    }

    if (left == 3 && right == 4) {
        if (g3[2] != g4[6])
            r34 = true;
        else
            r34 = false;
    }
}

void    cw(int num)
{
    if (num == 1) {
        string ng1 = "";
        ng1.push_back(g1[7]);
        for (int i = 0; i < 7; i++)
            ng1.push_back(g1[i]);
        g1 = ng1;
    }

    else if (num == 2) {
        string ng2 = "";
        ng2.push_back(g2[7]);
        for (int i = 0; i < 7; i++)
            ng2.push_back(g2[i]);
        g2 = ng2;
    }

    else if (num == 3) {
        string ng3 = "";
        ng3.push_back(g3[7]);
        for (int i = 0; i < 7; i++)
            ng3.push_back(g3[i]);
        g3 = ng3;
    }

    else {
        string ng4 = "";
        ng4.push_back(g4[7]);
        for (int i = 0; i < 7; i++)
            ng4.push_back(g4[i]);
        g4 = ng4;
    }
}

void    ccw(int num)
{
    if (num == 1) {
        string ng1 = g1.substr(1,7);
        ng1.push_back(g1[0]);
        g1 = ng1;
    }

    else if (num == 2) {
        string ng2 = g2.substr(1,7);
        ng2.push_back(g2[0]);
        g2 = ng2;
    }

    else if (num == 3) {
        string ng3 = g3.substr(1,7);
        ng3.push_back(g3[0]);
        g3 = ng3;
    }
    
    else {
        string ng4 = g4.substr(1,7);
        ng4.push_back(g4[0]);
        g4 = ng4;
    }
}

void    wheel(int num, int dir)
{
    // 기어 번호
    if (num == 1) {
        // 1 시계, -1 반시계
        if (dir == 1) {
            cw(1);
            // 1, 2의 극이 반대
            if (r12 == true) {
                ccw(2);
                // 2, 3의 극이 반대
                if (r23 == true) {
                    cw(3);
                    // 3, 4의 극이 반대
                    if (r34 == true) {
                        ccw(4);
                    }
                }
            }
            // 1, 2의 극이 동일
            else {
                // 아무일도 일어나지 않음
            }
        }
        else if (dir == -1) {
            ccw(1);
            if (r12 == true) {
                cw(2);
                if (r23 == true) {
                    ccw(3);
                    if (r34 == true)
                        cw(4);
                }
            }
        }
    }

    else if (num == 2) {
        if (dir == 1) {
            cw(2);
            if (r12 == true) {
                ccw(1);
            }
            if (r23 == true) {
                ccw(3);
                if (r34 == true)
                    cw(4);
            }
        }
        else if (dir == -1) {
            ccw(2);
            if (r12 == true) {
                cw(1);
            }
            if (r23 == true) {
                cw(3);
                if (r34 == true)
                    ccw(4);
            }
        }
    }

    else if (num == 3) {
        if (dir == 1) {
            cw(3);
            if (r34 == true) {
                ccw(4);
            }
            if (r23 == true) {
                ccw(2);
                if (r12 == true)
                    cw(1);
            }
        }
        else if (dir == -1) {
            ccw(3);
            if (r34 == true) {
                cw(4);
            }
            if (r23 == true) {
                cw(2);
                if (r12 == true)
                    ccw(1);
            }
        }
    }

    // 기어 번호
    else if (num == 4) {
        // 1 시계, -1 반시계
        if (dir == 1) {
            cw(4);
            // 3, 4의 극이 반대
            if (r34 == true) {
                ccw(3);
                // 2, 3의 극이 반대
                if (r23 == true) {
                    cw(2);
                    // 3, 4의 극이 반대
                    if (r12 == true) {
                        ccw(1);
                    }
                }
            }
            // 3, 4의 극이 동일
            else {
                // 아무일도 일어나지 않음
            }
        }
        else if (dir == -1) {
            ccw(4);
            if (r34 == true) {
                cw(3);
                if (r23 == true) {
                    ccw(2);
                    if (r12 == true)
                        cw(1);
                }
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>g1;cin>>g2;cin>>g3;cin>>g4;
    cin>>T;

    while (T--)
    {
        int num; int dir;
        cin>>num; cin>>dir;
        rel(1, 2); 
        rel(2, 3); 
        rel(3, 4);
        wheel(num, dir);
    }
    
    int ans = 0;
    if (g1[0] == '1')
        ans += 1;
    if (g2[0] == '1')
        ans += 2;
    if (g3[0] == '1')
        ans += 4;
    if (g4[0] == '1')
        ans += 8;

    cout << ans;
    return 0;
}
#include <iostream>
using namespace std;

const int MAX = 101010;

int n;
int arr[MAX];

int comp(int x, int y)
{
    return (x < y);
}

void    pop(void)
{
    int idx;
    int temp;

    arr[1] = arr[n--];
    idx = 1;
    while (idx <= n)
    {
        if (idx * 2 <= n && comp(arr[idx], arr[idx * 2]))
        {
            if (idx * 2 + 1 <= n && comp(arr[idx * 2], arr[idx * 2 + 1]))
            {
                temp = arr[idx * 2 + 1];
                arr[idx * 2 + 1] = arr[idx];
                arr[idx] = temp;
                idx = idx * 2 + 1;
            }
            else
            {
                temp = arr[idx * 2];
                arr[idx * 2] = arr[idx];
                arr[idx] = temp;
                idx = idx * 2;
            }
        }
        else if (idx * 2 + 1 <= n && comp(arr[idx], arr[idx * 2 + 1]))
        {
            temp = arr[idx * 2 + 1];
            arr[idx * 2 + 1] = arr[idx];
            arr[idx] = temp;
            idx = idx * 2 + 1;
        }
        else
            break ;
    }
}

void    push(int value)
{
    int idx;
    int temp;

    n++;
    arr[n] = value;
    idx = n;
    while (idx > 1 && comp(arr[idx / 2], arr[idx]))
    {
        temp = arr[idx / 2];
        arr[idx / 2] = arr[idx];
        arr[idx] = temp;
        idx = idx / 2;
    }
}

int top(void)
{
    return (arr[1]);
}

signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    int t;
    int x;

    cin>>t;
    while (t--)
    {
        cin>>x;
        if (x == 0)
        {
            if (n == 0)
                cout<<0<<'\n';
            else
            {
                cout<<top()<<'\n';
                pop();
            }
        }
        else
            push(x);
    }
    return 0;
}
#include <iostream>
#include <string>
#include <algorithm>

int min(int a, int b)
{
    if (a >= b)
        return b;
    return a;
}

int main()
{
    int a, b, val;
    std::cin>>a>>b;
    for(int i = 1; i <= min(a, b);i++)
    {
        if (a % i == 0 && b % i == 0)
            val = i;
    }
    std::cout << val << "\n" << a*b/val << "\n";
}

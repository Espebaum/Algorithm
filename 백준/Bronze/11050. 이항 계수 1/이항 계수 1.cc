#include <iostream>
#include <vector>
#include <algorithm>

int fac(int a)
{
    int ans = 1;
    for(int i = 1; i < a + 1; i++)
        ans *= i;
    return ans;
}

void    comb(int N, int K)
{
    std::cout << fac(N) / (fac(K) * fac(N - K)); 
}

int main()
{
    int N, K;
    std::cin >> N >> K;
    comb(N, K);
}

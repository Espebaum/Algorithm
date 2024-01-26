#include <iostream>
#include <string>
#include <algorithm>

void    print(std::string s)
{
    int size = s.size();
    int idx = size - 1;
    for(int i = 0; i <= (size / 2); i++)
    {
        if (s[i] != s[idx - i])
        {
            std::cout << "no\n";
            return ;
        }
    }
    std::cout << "yes\n";
}

int main()
{
    std::string s;
    while (1)
    {
        std::cin>>s;
        if (s == "0")
            break;
        print(s);
    }
}
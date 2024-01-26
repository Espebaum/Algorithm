#include <iostream>
#include <vector>
#include <algorithm>

int     square(int x)
{
	return (x * x);
}

void    print(int a, int b, int c)
{
	if (square(a) + square(b) == square(c)
			|| square(c) + square(b) == square(a)
				|| square(a) + square(c) == square(b))
		std::cout << "right\n";
	else
		std::cout << "wrong\n";
}

int main()
{
	int a, b, c;
	while(1)
	{
		std::cin>>a>>b>>c;
		if (a == 0 && b == 0 && c == 0)
			break ;
		print(a, b, c);
	}
	return (0);
}
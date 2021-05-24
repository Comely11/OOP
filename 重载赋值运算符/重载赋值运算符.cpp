
#include "hstring.h"
#include <iostream>


//重载赋值
int main()
{
	hstring strA{"12312321"};
	hstring strB{"对方是否"};
	strA + strB;

	std::cout << strA;
	std::cin >> strA;
	std::cout << strA;
}


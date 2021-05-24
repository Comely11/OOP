
#include "hstring.h"
#include <iostream>

int main()
{
	//第一种做法
 //  //hstring str{"21e21"};
 //   //int val = -1234123;
 //   unsigned int val= -1;
 //   char str[12]{};
	//char strR[12]{};
 //   int len{};
 //   bool bfs = val < 0;
 //   if (bfs)val =-1*val;
 //  
 //   do 
 //   {
 //       str[len++] = val % 10 + 48;
 //       val = val / 10;
 //   } while (val);
 //   if (bfs)str[len++] = '-';
	//for (int i=0;str[i];i++)
	//{
 //      // len -=1;
 //       strR[i] = str[len-i-1];
	//}
 // 
 //   std::cout << strR;

	//第二种做法 只用一个循环

	//hstring str{"21e21"};
    //int val = 1234123;
	//unsigned int val= 1;
 //   char str[12]{};
	//char strR[12]{};
 //   int len{11};
 //   bool bfs = val < 0;
	//if (bfs)val = -1 * val;
	//

	//do 
	//{
	//	str[--len] = val % 10 + 48;
	//	val = val / 10;
	//	
	//} while (val);

	//std::cout << &str[len];
	//3.精简代码

//hstring str{ "21e21" };
	   //int val = -1234123;
	   //long long val= -1;
	   //char str[0x20]{};
	   //char strR[0x1F]{};
	   //int len{11};
	   //bool bzs = val >= 0;
	   //val =val*(bzs*2-1);//val= 0*2-1=0-1;1*2-1=1;
	   //do 
	   //{ str[--len] = val % 10 + 48;
	   //} while (val = val / 10);
	   //str[len = len - 1 * (1 - bzs)] = '-' * (bzs + 1) * (1 - bzs) + str[len] * bzs;
	   //std::cout << &str[len];
	hstring str = "123abc";
	str = str + 1234123;
	std::cout << str;


}


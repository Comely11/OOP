#pragma once
#ifndef _HTDSTRING_
#define _HTDSTRING_
#include <iostream>
#define hstring_no_char  -1;
class hstring
{

	unsigned  short usmlen;//字符串的内存长度
	char* cstr;//字符串的内容
	unsigned  short uslen;//字符串的长度
	unsigned short GetLength(const char* str)const;
	void CopyStrs(char* dest, const char* source);
public:
	inline static char nochar = -1;
	char* c_cstr()
	{
		return cstr;
	}
	//hstring();
	hstring(char clen=0x32);
	hstring(int val);
	~hstring();
	hstring(const char* str);//利用c字符串来构造hstring
	hstring(const hstring& str);//利用hstring 来构造hstring
	hstring& operator=(const hstring& str);
	//  hstring& operator=(const int &value);//实现int类型
	  //hstring& operator=(const long long &value);//实现longlong类型
	hstring& operator<<(const hstring& str);
	hstring& operator+(const hstring& str);
	hstring& operator+(const hstring&& str);

	//hstring& operator

	//bool ResetMemory(unsigned short);//重新设定缓冲区的大小
	//unsigned short GetMemory()//获取当前缓冲区大小
	//unsigned short GetLength()//获取当前字符串长度
	const char& operator[](const unsigned short index)const;
	//const char& operator[](const char*key)const;返回key后面的内容
	const char& operator()();
	hstring operator()(const unsigned short start, const unsigned short legth)const;//截取字符串
	hstring& operator+(int val);
	hstring& operator+(unsigned val);
	hstring& operator+(float val);

	explicit operator int();
};
std::ostream& operator<<(std::ostream& _cout, hstring&& _str);
std::istream& operator>>(std::istream& _cin, hstring& _str);
std::ostream& operator<<(std::ostream& _cout, hstring& _str);


#endif
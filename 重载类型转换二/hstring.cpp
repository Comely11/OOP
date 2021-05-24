#include "hstring.h"
#include <iostream>
hstring::hstring(const char* str) :hstring()
{
	CopyStrs(cstr, str);
}

hstring::hstring(const hstring& str) : hstring()
{
	CopyStrs(cstr, str.cstr);
}

unsigned short hstring::GetLength(const char* str) const
{
	unsigned short len = 0;
	for (; str[len++];);
	return len;
}

void hstring::CopyStrs(char* dest, const char* source)
{
	unsigned short len = GetLength(source);
	if (len > usmlen)
	{
		delete[] cstr;
		cstr = new char[len];
		usmlen = len;
	}
	memcpy(cstr, source, len);
	uslen = len;//字符串长度修正;

}

hstring::hstring(char clen) {
	usmlen = clen;//字符串空间
	uslen = 1;//字符串长度
	cstr = new char[usmlen];
	std::cout << "类被构造";
}

hstring::hstring(int val) :hstring()
{
	char str[0x20]{};
	int len{ 0x1F };
	bool bzs = val >= 0;
	val = val * (bzs * 2 - 1);//val= 0*2-1=0-1;1*2-1=1;
	do
	{
		str[--len] = val % 10 + 48;
	} while (val = val / 10);

	str[len = len - 1 * (1 - bzs)] = '-' * (bzs + 1) * (1 - bzs) + str[len] * bzs;
	unsigned short slen = uslen + 0x20 - len - 1;


	if (slen > usmlen)
	{
		char* lstr = cstr;
		cstr = new char[slen];
		usmlen = slen;
		memcpy(cstr, lstr, uslen);
		delete[] cstr;
	}
	memcpy(cstr + uslen - 1, str + len, 0x20 - len);
	uslen = slen;//字符串长度修正;
	//return *this;


}

hstring& hstring::operator=(const hstring& str)
{
	CopyStrs(cstr, str.cstr);
	return *this;
}

hstring& hstring::operator<<(const hstring& str) {
	unsigned short slen = GetLength(str.cstr);
	slen = uslen + slen + 1;
	if (slen > usmlen)
	{
		char* lstr = cstr;
		cstr = new char[slen];
		usmlen = slen;
		memcpy(cstr, lstr, uslen);
		delete[] cstr;
	}
	memcpy(cstr + uslen - 1, str.cstr, slen - uslen + 1);
	uslen = slen;//字符串长度修正;
	return *this;
}

hstring& hstring::operator+(const hstring& str) {
	return *this << str;
}

hstring& hstring::operator+(const hstring&& str)
{
	return *this << str;
}

const char& hstring::operator[](const unsigned short index) const
{
	if (index > uslen) {
		return nochar;
	}
	else
	{
		return cstr[index];
	}
}

const char& hstring::operator()()
{
	return cstr[0];
}
hstring hstring::operator()(const unsigned short start, const unsigned short legth)const
{
	if (start > uslen - 2)
	{
		return hstring("");
	}
	unsigned slen = start + legth > uslen - 1 ? uslen - start - 1 : legth;
	char* newstr = new char[slen + 1];
	memcpy(newstr, cstr + start, slen + 1);
	newstr[slen];
	return hstring(newstr);
}

hstring& hstring::operator+(int val)
{
	//long long val = -1;
	char str[0x20]{};
	int len{ 0x1F };
	bool bzs = val >= 0;
	val = val * (bzs * 2 - 1);//val= 0*2-1=0-1;1*2-1=1;
	do
	{
		str[--len] = val % 10 + 48;
	} while (val = val / 10);

	str[len = len - 1 * (1 - bzs)] = '-' * (bzs + 1) * (1 - bzs) + str[len] * bzs;
	unsigned short slen = uslen + 0x20 - len - 1;


	if (slen > usmlen)
	{
		char* lstr = cstr;
		cstr = new char[slen];
		usmlen = slen;
		memcpy(cstr, lstr, uslen);
		delete[] cstr;
	}
	memcpy(cstr + uslen - 1, str + len, 0x20 - len);
	uslen = slen;//字符串长度修正;
	return *this;


}

hstring& hstring::operator+(unsigned val)
{
	// TODO: 在此处插入 return 语句
	return *this;
}

hstring& hstring::operator+(float val)
{
	// TODO: 在此处插入 return 语句
	return *this;
}

hstring::operator int()
{

	int val{ 0 };
	int i{ cstr[0] == '-' };
	while (cstr[i] >= '0' && cstr[i] <= '9')
	{
		val = val * 10 + cstr[i++] - 48;
	}
	val = val * ((cstr[0] != '-') * 2 - 1);//如果是负数则乘以负一
	return val;

}

hstring::~hstring() {
	if (cstr != nullptr)delete[]cstr;
}//结束即删除内存
std::ostream& operator<<(std::ostream& _cout, hstring&& _str)
{
	_cout << _str.c_cstr();
	return _cout;
}

std::ostream& operator<<(std::ostream& _cout, hstring& _str)
{
	_cout << _str.c_cstr();
	return _cout;
}
std::istream& operator>>(std::istream& _cin, hstring& _str)
{
	char _sRead[0xff]{};

	_cin >> _sRead;
	_str = _sRead;
	return _cin;
}

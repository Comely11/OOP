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
	uslen = len;//�ַ�����������;

}

hstring::hstring() {
	usmlen = 0x32;//�ַ����ռ�
	uslen = 0;//�ַ�������
	cstr = new char[usmlen];

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
	uslen = slen;//�ַ�����������;
	return *this;
}

hstring& hstring::operator+(const hstring& str) {
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

hstring::~hstring() {
	if (cstr != nullptr)delete[]cstr;
}//������ɾ���ڴ�
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

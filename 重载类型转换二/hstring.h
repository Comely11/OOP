#pragma once
#ifndef _HTDSTRING_
#define _HTDSTRING_
#include <iostream>
#define hstring_no_char  -1;
class hstring
{

	unsigned  short usmlen;//�ַ������ڴ泤��
	char* cstr;//�ַ���������
	unsigned  short uslen;//�ַ����ĳ���
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
	hstring(const char* str);//����c�ַ���������hstring
	hstring(const hstring& str);//����hstring ������hstring
	hstring& operator=(const hstring& str);
	//  hstring& operator=(const int &value);//ʵ��int����
	  //hstring& operator=(const long long &value);//ʵ��longlong����
	hstring& operator<<(const hstring& str);
	hstring& operator+(const hstring& str);
	hstring& operator+(const hstring&& str);

	//hstring& operator

	//bool ResetMemory(unsigned short);//�����趨�������Ĵ�С
	//unsigned short GetMemory()//��ȡ��ǰ��������С
	//unsigned short GetLength()//��ȡ��ǰ�ַ�������
	const char& operator[](const unsigned short index)const;
	//const char& operator[](const char*key)const;����key���������
	const char& operator()();
	hstring operator()(const unsigned short start, const unsigned short legth)const;//��ȡ�ַ���
	hstring& operator+(int val);
	hstring& operator+(unsigned val);
	hstring& operator+(float val);

	explicit operator int();
};
std::ostream& operator<<(std::ostream& _cout, hstring&& _str);
std::istream& operator>>(std::istream& _cin, hstring& _str);
std::ostream& operator<<(std::ostream& _cout, hstring& _str);


#endif
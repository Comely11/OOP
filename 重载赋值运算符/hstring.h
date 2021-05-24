#pragma once
#ifndef _HTDSTRING_
#define _HTDSTRING_
#include <iostream>
class hstring
{
	unsigned  short usmlen;//�ַ������ڴ泤��
	char* cstr;//�ַ���������
	unsigned  short uslen;//�ַ����ĳ���
	unsigned short GetLength(const char* str)const;
	void CopyStrs(char* dest, const char* source);
public:
	char* c_cstr()
	{
		return cstr;
	}
	hstring();
	~hstring();
	hstring(const char* str);//����c�ַ���������hstring
	hstring(const hstring& str);//����hstring ������hstring
	hstring& operator=(const hstring& str);
	//  hstring& operator=(const int &value);//ʵ��int����
	  //hstring& operator=(const long long &value);//ʵ��longlong����
	hstring& operator<<(const hstring& str);
	hstring& operator+(const hstring& str);

	//bool ResetMemory(unsigned short);//�����趨�������Ĵ�С
	//unsigned short GetMemory()//��ȡ��ǰ��������С
	//unsigned short GetLength()//��ȡ��ǰ�ַ�������

};
std::ostream& operator<<(std::ostream& _cout, hstring&  _str);
std::istream& operator>>(std::istream& _cin, hstring&  _str);


#endif
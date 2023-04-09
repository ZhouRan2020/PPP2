#pragma once


#include <initializer_list>
#include <algorithm>
#include <string>
#include <iostream>
#include <utility>
#include <memory>

struct out_of_range {};

template<typename T>
class vector {

	int sz;
	T* elem;
	int space;

public:

	//Ĭ�Ϲ��캯��
	vector();
	//���캯��:����Ԫ������
	explicit vector(int);
	//���캯��:���ݳ�ʼ�����б�
	explicit vector(std::initializer_list<T>);
	//������캯����vector����ֵ����
	explicit vector(const vector&);
	//�����ֵ��vector����ֵ����
	vector& operator=(const vector&);
	//�ƶ����캯������������ʱʹ��
	explicit vector(vector&&) noexcept;
	//�ƶ���ֵ����������ʱʹ��
	vector& operator=(vector&&) noexcept;
	//��������
	~vector();

	//���ʣ���������
	T& operator[](int);
	const T& operator[](int) const;
	T& at(int);

	//��ѯ����
	int capacity() const;
	int size() const;

	//���ƴ�С�仯
	void reserve(int);
	void resize(int, T);
	void push_back(const T&);
};

//myvector���͵�Ĭ�Ϲ��캯��
template<typename T>
vector<T>::vector()
	:sz{ 0 }, elem{ nullptr }, space{ 0 }
{
}

//myvector���͵ġ���ͨ�����캯��
template<typename T>
vector<T>::vector(int s)
	:sz{ s }, elem{ new T[sz] }, space{ 0 }
{
}

//myvector���͵ġ���ͨ�����캯��
template<typename T>
vector<T>::vector(std::initializer_list<T> lst)
	:sz{ static_cast<int>(lst.size()) }, elem{ new T[sz] }, space{ 0 }
{
	std::copy(lst.begin(), lst.end(), elem);
}

//myvector���͵Ŀ������캯����myvector���;���������캯��������ֵ����
template<typename T>
vector<T>::vector(const vector& arg)
	:sz{ arg.sz }, elem{ new T[arg.sz] }, space{ 0 }
{
	std::copy(arg.elem, arg.elem + (arg.sz - 1), elem);
}

//myvector���͵Ŀ�����ֵ������myvector���;��������ֵ����������ֵ����
template<typename T>
vector<T>& vector<T>::operator=(const vector& a)
{
	if (this == &a) return *this;

	if (a.sz <= space) {
		for (int i = 0; i < a.sz; ++i) elem[i] = a.elem[i];
	}

	T* p = new T[a.sz];

	for (int i = 0; i < a.sz; ++i) p[i] = a.elem[i];

	delete[] elem;

	elem = p;

	space = sz = a.sz;

	return *this;
}

//myvector���͵��ƶ����캯��
template<typename T>
vector<T>::vector(vector&& a) noexcept
	:sz{ a.sz }, elem{ a.elem }, space{ 0 }
{
	a.sz = 0;
	a.elem = nullptr;
}

//myvector���͵��ƶ���ֵ����
template<typename T>
vector<T>& vector<T>::operator=(vector&& a) noexcept
{
	delete[] elem;
	elem = a.elem;
	sz = a.sz;
	a.elem = nullptr;
	a.sz = 0;
	return *this;
}

//myvector���͵���������
template<typename T>
vector<T>::~vector()
{
	delete[] elem;
}


template<typename T>
T& vector<T>::operator[] (int n)
{
	return elem[n];
}

template<typename T>
const T& vector<T>::operator[] (int n) const
{
	return elem[n];
}

template<typename T>
T& vector<T>::at(int n)
{
	if (n < 0 || sz <= n) { throw out_of_range(); }
	return elem[n];
}

template<typename T>
int vector<T>::size() const
{
	return sz;
}

template<typename T>
int vector<T>::capacity() const
{
	return space;
}

template<typename T>
void vector<T>::reserve(int newalloc)
{
	if (newalloc <= space) { return; }


	double* p = new double[newalloc];

	for (int i = 0; i < sz; ++i)
	{
		p[i] = elem[i];
	}
	delete[] elem;
	elem = p;
	space = newalloc;
}

template<typename T>
void vector<T>::resize(int newsize, T val)
{
	reserve(newsize);
	for (int i = sz; i < newsize; ++i) { elem[i] = val; }
	sz = newsize;
}

template<typename T>
void vector<T>::push_back(const T& d)
{
	if (space == 0)
		reserve(8);
	else if (sz == space)
		reserve(2 * space);
	elem[sz] = d;
	++sz;
}






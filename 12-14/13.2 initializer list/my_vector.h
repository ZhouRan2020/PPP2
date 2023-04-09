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

	//默认构造函数
	vector();
	//构造函数:根据元素数量
	explicit vector(int);
	//构造函数:根据初始化器列表
	explicit vector(std::initializer_list<T>);
	//深拷贝构造函数，vector具有值语义
	explicit vector(const vector&);
	//深拷贝赋值，vector具有值语义
	vector& operator=(const vector&);
	//移动构造函数，函数返回时使用
	explicit vector(vector&&) noexcept;
	//移动赋值，函数返回时使用
	vector& operator=(vector&&) noexcept;
	//析构函数
	~vector();

	//访问：返回引用
	T& operator[](int);
	const T& operator[](int) const;
	T& at(int);

	//查询操作
	int capacity() const;
	int size() const;

	//控制大小变化
	void reserve(int);
	void resize(int, T);
	void push_back(const T&);
};

//myvector类型的默认构造函数
template<typename T>
vector<T>::vector()
	:sz{ 0 }, elem{ nullptr }, space{ 0 }
{
}

//myvector类型的“普通”构造函数
template<typename T>
vector<T>::vector(int s)
	:sz{ s }, elem{ new T[sz] }, space{ 0 }
{
}

//myvector类型的“普通”构造函数
template<typename T>
vector<T>::vector(std::initializer_list<T> lst)
	:sz{ static_cast<int>(lst.size()) }, elem{ new T[sz] }, space{ 0 }
{
	std::copy(lst.begin(), lst.end(), elem);
}

//myvector类型的拷贝构造函数，myvector类型具有深拷贝构造函数，具有值语义
template<typename T>
vector<T>::vector(const vector& arg)
	:sz{ arg.sz }, elem{ new T[arg.sz] }, space{ 0 }
{
	std::copy(arg.elem, arg.elem + (arg.sz - 1), elem);
}

//myvector类型的拷贝赋值函数，myvector类型具有深拷贝赋值函数，具有值语义
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

//myvector类型的移动构造函数
template<typename T>
vector<T>::vector(vector&& a) noexcept
	:sz{ a.sz }, elem{ a.elem }, space{ 0 }
{
	a.sz = 0;
	a.elem = nullptr;
}

//myvector类型的移动赋值函数
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

//myvector类型的析构函数
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






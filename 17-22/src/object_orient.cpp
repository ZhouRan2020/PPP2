//c++面向对象：封装encapsulation、继承inheritance、多态polymorphism--类class
#include<iostream>
class B1 {
public:
	virtual void vf() { std::cout << "B1::vf()\n"; }
		    void  f() { std::cout << "B1:: f()\n"; }
		virtual	void pvf() =0 { std::cout << "B1::pvf()\n"; }
};

class D1 : public B1 {
public:
	void vf() override { std::cout << "D1::vf()\n"; }
	void f() { std::cout << "D1::f()\n"; }
	void pvf() override { std::cout << "D1::pvf()\n"; }
};

class D2 :public D1 {
public:
	//void vf()  { std::cout << "D2::vf()\n"; }
	//void f() { std::cout << "D2::f()\n"; }
	void pvf() override { std::cout << "D2::pvf()\n"; }
};

int main() {
	//B1 b1;
	//b1.vf();
	//b1.f();
	D1 d1;
	d1.vf();
	d1.f();
	d1.pvf();
	B1& b11{ d1 };
	b11.vf();
	b11.f();
	b11.pvf();
	D2 d2;
	d2.vf();
	d2.f();
	d2.pvf();

	getchar();

	return 0;
}
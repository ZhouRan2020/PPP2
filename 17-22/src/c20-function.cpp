//��ע�⣺fltk1.1.10��32λlib��������debug-x86�����µ���
#include "Simple_window.h"    // get access to our window library
#include "Graph.h"            // get access to our graphics library facilities

double one(double x) { return 1; }

double slope(double x) { return x / 2; }

double square(double x) { return x * x; }

//double sloping_cos(double x) { return cos(x) + slope(x); }
//------------------------------------------------------------------------------

int main()
{
	using namespace Graph_lib;   // our graphics facilities are in Graph_lib

	constexpr int xmax = 700;
	constexpr int ymax = 700;
	constexpr int x_orig = xmax / 2;
	constexpr int y_orig = ymax / 2;
	constexpr Point orig{ x_orig,y_orig };
	constexpr int r_min = -10;
	constexpr int r_max = 11;
	constexpr int n_points = 400;
	constexpr int x_scale = 35;
	constexpr int y_scale = 35;

	//��������ͼ�����
	Simple_window win{ Point{100,100},xmax,ymax,"Function graphing" };
	Function s{ one,r_min,r_max,orig,n_points,x_scale,y_scale };
	Function s2{ slope,r_min,r_max,orig,n_points,x_scale,y_scale };
	Function s3{ square,r_min,r_max,orig,n_points,x_scale,y_scale };
	win.attach(s);
	win.attach(s2);
	win.attach(s3);
	win.wait_for_button();   // give control to the display engine

	//�����ı�����
	Text ts{ {100,y_orig - 40},"one" };
	Text ts2{ {100,y_orig +y_orig/2-20},"x/2" };
	Text ts3{ {x_orig-100,20},"x^2" };
	win.attach(ts);
	win.attach(ts2);
	win.attach(ts3);
	win.set_label( "f g : l f" );
	win.wait_for_button();

	constexpr int xlength = xmax - 40;
	constexpr int ylength = ymax - 40;

	//�������������
	Axis x{ Axis::x,{20,y_orig},xlength,xlength / x_scale,"one notch==1" };
	Axis y{ Axis::y,{x_orig,ylength+20},ylength,ylength / y_scale,"one notch==1" };
	x.set_color(Color::red);
	y.set_color(Color::blue);
	win.attach(x);
	win.attach(y);
	win.set_label("f g : l f");
	win.wait_for_button();

	//��������ͼ�����
	Function s4{ cos,r_min,r_max,orig,n_points,x_scale,y_scale };
	Function s5{ [](double x) {return cos(x) + slope(x); },r_min,r_max,orig,n_points,x_scale,y_scale };
	s4.set_color(Color::red);
	x.label.move(-160, 0);
	x.notches.set_color(Color::dark_red);
	win.attach(s4);
	win.attach(s5);
	win.wait_for_button();	
	return 0;
}
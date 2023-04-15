//请注意：fltk1.1.10是32位lib所以请在debug-x86环境下调试
#include "Simple_window.h"    // get access to our window library
#include "Graph.h"            // get access to our graphics library facilities

double one(double x) { return 1; }

double slope(double x) { return x / 2; }

double square(double x) { return x * x; }

//double sloping_cos(double x) { return cos(x) + slope(x); }
//------------------------------------------------------------------------------

int main()
{
//	using namespace Graph_lib;   // our graphics facilities are in Graph_lib

	constexpr int xmax = 700;
	constexpr int ymax = 700;
	constexpr int x_orig = xmax / 2;
	constexpr int y_orig = ymax / 2;
	const gl::Point orig{ x_orig,y_orig };
	constexpr int r_min = -10;
	constexpr int r_max = 11;
	constexpr int n_points = 400;
	constexpr int x_scale = 35;
	constexpr int y_scale = 35;

	//建立函数图像对象
	gl::Simple_window win{ gl::Point{100,100},xmax,ymax,"Function graphing" };
	win.wait_for_button();	
	gl::Function s{ one,r_min,r_max,orig,n_points,x_scale,y_scale };
	gl::Function s2{ slope,r_min,r_max,orig,n_points,x_scale,y_scale };
	gl::Function s3{ square,r_min,r_max,orig,n_points,x_scale,y_scale };
	win.attach(s);
	win.wait_for_button();	
	win.attach(s2);
	win.wait_for_button();	
	win.attach(s3);
	win.wait_for_button();   // give control to the display engine

	//建立文本对象
	gl::Text ts{ {100,y_orig - 40},"one" };
	gl::Text ts2{ {100,y_orig +y_orig/2-20},"x/2" };
	gl::Text ts3{ {x_orig-100,20},"x^2" };
	win.attach(ts);
	win.wait_for_button();	
	win.attach(ts2);
	win.wait_for_button();	
	win.attach(ts3);
	win.wait_for_button();	
	win.set_label( "f g : l f" );
	win.wait_for_button();

	constexpr int xlength = xmax - 40;
	constexpr int ylength = ymax - 40;

	//建立坐标轴对象
	gl::Axis x{ gl::Axis::x,{20,y_orig},xlength,xlength / x_scale,"one notch==1" };
	gl::Axis y{ gl::Axis::y,{x_orig,ylength+20},ylength,ylength / y_scale,"one notch==1" };
	x.set_color(gl::Color::red);
	y.set_color(gl::Color::blue);
	win.attach(x);
	win.wait_for_button();	
	win.attach(y);
	win.wait_for_button();	
	win.set_label("f g : l f");
	win.wait_for_button();

	//建立函数图像对象
	gl::Function s4{ cos,r_min,r_max,orig,n_points,x_scale,y_scale };
	gl::Function s5{ [=](double x) {return cos(x) + slope(x); },r_min,r_max,orig,n_points,x_scale,y_scale };
	s4.set_color(gl::Color::red);
	x.label.move(-160, 0);
	x.notches.set_color(gl::Color::dark_red);
	win.attach(s4);
	win.wait_for_button();	
	win.attach(s5);
	win.wait_for_button();	
	return 0;
}
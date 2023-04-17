#include "Simple_window.h"    // get access to our window library
#include "Graph.h"            // get access to our graphics library facilities
//#include "Point.h"
//#include <iostream>
//------------------------------------------------------------------------------

int main()
{
    //using namespace Graph_lib;   // our graphics facilities are in Graph_lib
	//��������
    gl::Point left_up(100, 100);          // to become top left  corner of window
	//gl::Color c1(gl::Color::red); 
	// std::cout<<c1.as_int();
	// Fl_Color fc1{};
	// std::cout<<fc1;
	Simple_window win(left_up, 700, 700, "project");    // make a simple window
	int x_size = win.x_max();
	int y_size = win.y_max();
	int x_grid = 80;
	int y_grid = 40;

    win.wait_for_button();       // give control to the display engine
	////����դ��
	gl::Lines grid;
	for (int x = x_grid; x < x_size; x += x_grid)
	 	grid.add(gl::Point{ x,0 }, gl::Point{ x,y_size });
	for (int y = y_grid; y < y_size; y += y_grid)
	 	grid.add(gl::Point{ 0,y }, gl::Point{ x_size,y });
	grid.set_color(gl::Color::cyan);
	grid.set_style(gl::Line_style{gl::Line_style::dash,2});
	win.attach(grid);

    win.wait_for_button();       // give control to the display engine
	////����������
	gl::Rectangle rect00{ gl::Point{150,100},200,100 };
	rect00.set_fill_color(gl::Color::yellow);
	gl::Rectangle rect11{ gl::Point{50,50},gl::Point{250,150} };
	rect11.set_fill_color(gl::Color::blue);
	rect11.move(400, 0);
	gl::Rectangle rect12{ gl::Point{50,150},gl::Point{250,250} };
	rect12.set_fill_color(gl::Color::red);
	gl::Rectangle rect21{ gl::Point{250,50},200,100 };
	rect21.set_fill_color(gl::Color::green);
	gl::Rectangle rect22{ gl::Point{250,150},200,100 };
	rect00.set_color(gl::Color::invisible);
	rect11.set_color(gl::Color::invisible);
	rect12.set_color(gl::Color::invisible);
	rect21.set_color(gl::Color::invisible);
	rect22.set_color(gl::Color::invisible);
	win.attach(rect00);
	win.attach(rect11);
	win.attach(rect12);
	win.attach(rect21);
	win.attach(rect22);
    win.wait_for_button();       // give control to the display engine
	win.put_on_top(rect00);

    win.wait_for_button();       // give control to the display engine
}

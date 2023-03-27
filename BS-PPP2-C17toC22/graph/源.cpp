
//
// This is example code from Chapter 12.3 "A first example" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include "Simple_window.h"    // get access to our window library
#include "Graph.h"            // get access to our graphics library facilities

//------------------------------------------------------------------------------

int main()
{
    using namespace Graph_lib;   // our graphics facilities are in Graph_lib
	//创建窗口
	Point leftup(100, 100);           // to become top left  corner of window
	Simple_window win(leftup, 700, 700, "project");    // make a simple window
	int x_size = win.x_max();
	int y_size = win.y_max();
	int x_grid = 80;
	int y_grid = 40;

	//创建栅格
	Lines grid;
	for (int x = x_grid; x < x_size; x += x_grid)
		grid.add(Point{ x,0 }, Point{ x,y_size });
	for (int y = y_grid; y < y_size; y += y_grid)
		grid.add(Point{ 0,y }, Point{ x_size,y });
	grid.set_color(Color::cyan);
	grid.set_style(Line_style{Line_style::dash,2});
	win.attach(grid);

	//创建长方形
	Rectangle rect00{ Point{150,100},200,100 };
	rect00.set_fill_color(Color::yellow);
	Rectangle rect11{ Point{50,50},Point{250,150} };
	rect11.set_fill_color(Color::blue);
	rect11.move(400, 0);
	Rectangle rect12{ Point{50,150},Point{250,250} };
	rect12.set_fill_color(Color::red);
	Rectangle rect21{ Point{250,50},200,100 };
	rect21.set_fill_color(Color::green);
	Rectangle rect22{ Point{250,150},200,100 };
	rect00.set_color(Color::invisible);
	rect11.set_color(Color::invisible);
	rect12.set_color(Color::invisible);
	rect21.set_color(Color::invisible);
	rect22.set_color(Color::invisible);
	win.attach(rect00);
	win.attach(rect11);
	win.attach(rect12);
	win.attach(rect21);
	win.attach(rect22);
	win.put_on_top(rect00);

    win.wait_for_button();       // give control to the display engine
}

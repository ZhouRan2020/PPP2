//#include "Simple_window.h"    // get access to our window library
#include "Graph.h"            // get access to our graphics library facilities
#include "Point.h"
#include <iostream>
//------------------------------------------------------------------------------

int main()
{
    //using namespace Graph_lib;   // our graphics facilities are in Graph_lib
	//��������
    Graph_lib::Point left_up(100, 100);          // to become top left  corner of window
	Graph_lib::Color c1(Graph_lib::Color::red); 
	cout<<c1.as_int();
	Fl_Color fc1{};
	cout<<fc1;
	//Simple_window win(leftup, 700, 700, "project");    // make a simple window
	//int x_size = win.x_max();
	//int y_size = win.y_max();
	//int x_grid = 80;
	//int y_grid = 40;

	////����դ��
	//Lines grid;
	//for (int x = x_grid; x < x_size; x += x_grid)
	//	grid.add(Point{ x,0 }, Point{ x,y_size });
	//for (int y = y_grid; y < y_size; y += y_grid)
	//	grid.add(Point{ 0,y }, Point{ x_size,y });
	//grid.set_color(Color::cyan);
	//grid.set_style(Line_style{Line_style::dash,2});
	//win.attach(grid);

	////����������
	//Graph_lib::Rectangle rect00{ Point{150,100},200,100 };
	//rect00.set_fill_color(Color::yellow);
	//Graph_lib::Rectangle rect11{ Point{50,50},Point{250,150} };
	//rect11.set_fill_color(Color::blue);
	//rect11.move(400, 0);
	//Graph_lib::Rectangle rect12{ Point{50,150},Point{250,250} };
	//rect12.set_fill_color(Color::red);
	//Graph_lib::Rectangle rect21{ Point{250,50},200,100 };
	//rect21.set_fill_color(Color::green);
	//Graph_lib::Rectangle rect22{ Point{250,150},200,100 };
	//rect00.set_color(Color::invisible);
	//rect11.set_color(Color::invisible);
	//rect12.set_color(Color::invisible);
	//rect21.set_color(Color::invisible);
	//rect22.set_color(Color::invisible);
	//win.attach(rect00);
	//win.attach(rect11);
	//win.attach(rect12);
	//win.attach(rect21);
	//win.attach(rect22);
	//win.put_on_top(rect00);

 //   win.wait_for_button();       // give control to the display engine
}

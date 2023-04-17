
//
// This is example code from Chapter 12.3 "A first example" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include "Simple_window.h"    // get access to our window library
#include "Graph.h"            // get access to our graphics library facilities

//------------------------------------------------------------------------------

int main()
{
//	using namespace Graph_lib;   // our graphics facilities are in Graph_lib




	gl::Point leftup(100, 100);           // to become top left  corner of window
	Simple_window win(leftup, 800, 800, "project");    // make a simple window
	win.wait_for_button();       // give control to the display engine
	Vector_ref<gl::Rectangle> vr;
	for(int i=0;i<16;++i)
		for (int j = 0; j < 16; ++j) {
			vr.push_back(new gl::Rectangle{ gl::Point{i * 20,j * 20},20,20 });
			vr[vr.size() - 1].set_fill_color(gl::Color{ i * 16 + j });
			win.attach(vr[vr.size() - 1]);
		}

	win.wait_for_button();       // give control to the display engine
	gl::Marked_polyline mpl{ "abcd" };
	mpl.add(gl::Point{ 100,100 });
	mpl.add(gl::Point{ 150,200 });
	mpl.add(gl::Point{ 250,250 });
	mpl.add(gl::Point{ 300,200 });
	win.attach(mpl);
	win.wait_for_button();       // give control to the display engine

	gl::Marks pp { "ab" };
	
	pp.add(gl::Point{ 400,400 });
	pp.add(gl::Point{ 450,500 });
	pp.add(gl::Point{ 550,550 });
	pp.add(gl::Point{ 500,500 });
	win.attach(pp);
	win.wait_for_button();       // give control to the display engine

	gl::Mark p{ {600,600},'x' };
	win.attach(p);
	win.wait_for_button();       // give control to the display engine

	gl::Image qjl{ gl::Point{400,400},"resource/qjl.jpg",gl::Suffix::jpg};
	win.attach(qjl);

	/*
	int x_size = win.x_max();
	int y_size = win.y_max();
	int x_grid = 80;
	int y_grid = 40;

	Lines grid;
	for (int x = x_grid; x < x_size; x += x_grid)
		grid.add(Point{ x,0 }, Point{ x,y_size });
	for (int y = y_grid; y < y_size; y += y_grid)
		grid.add(Point{ 0,y }, Point{ x_size,y });
	grid.set_color(Color::cyan);
	grid.set_style(Line_style{ Line_style::dash,2 });
	win.attach(grid);

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

	*/
	/*
	//x axis
	Axis xa{ Axis::x,Point{20,300},280,10,"x axis" };
	win.attach(xa);

	//y axis
	Axis ya{ Axis::y,Point{20,300},280,10,"y axis" };
	ya.set_color(Color::cyan);
	ya.label.set_color(Color::dark_red);
	win.attach(ya);

	//sin function
	Function sine{ sin,0,100,Point{20,150},1000,50,50 };
	sine.set_color(Color::blue);
	win.attach(sine);

	//polygon
	Polygon poly;
	poly.add(Point{ 300,200 });
	poly.add(Point{ 350,100 });
	poly.add(Point{ 400,200 });
	poly.set_color(Color::red);
	poly.set_style(Line_style(Line_style::dash, 4));
	win.attach(poly);

	//rectangle
	Rectangle r{ Point{200,300},100,50 };
	r.set_fill_color(Color::yellow);
	win.attach(r);

	//closed polyline
	Closed_polyline poly_rect;
	poly_rect.add(Point{ 100,50 });
	poly_rect.add(Point{ 200,50 });
	poly_rect.add(Point{ 200,100 });
	poly_rect.add(Point{ 100,100 });
	poly_rect.add(Point{ 50,75 });
	poly_rect.set_style(Line_style(Line_style::dash, 2));
	poly_rect.set_fill_color(Color::green);
	win.attach(poly_rect);

	//text
	Text t{ Point{150,150},"Hello, graphical world!" };
	t.set_font(Font::times_bold);
	t.set_fill_color(20);
	win.attach(t);

	Image ii{ Point{100,50},"picture.jpg" };
	ii.set_mask(Point{ 500,500 }, 200, 150);
	ii.move(200, 200);
	win.attach(ii);

	Circle c{ Point{100,200},50 };
	Ellipse e{ Point{100,200},75,25 };
	e.set_color(Color::dark_red);
	Mark m{ Point{100,200},'x' };
	win.attach(c);
	win.attach(e);
	win.attach(m);

	ostringstream oss;
	oss << "screen size:" << x_max() << "*" << y_max() << ";window_size:" << win.x_max() << "*" << win.y_max();
	Text sizes{ Point{100,20},oss.str() };
	win.attach(sizes);




	win.set_label("canvas");

	// Graph_lib::Polygon poly;                // make a shape (a polygon)

   //  poly.add(Graph_lib::Point(300, 200));    // add a point
	// poly.add(Graph_lib::Point(350, 100));    // add another point
	// poly.add(Graph_lib::Point(400, 200));    // add a third point

	// poly.set_color(Graph_lib::Color::red);  // adjust properties of poly

	// win.attach(poly);           // connect poly to the window*/

	win.wait_for_button();       // give control to the display engine
}



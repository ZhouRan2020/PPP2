
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
	//创建调色盘
	Vector_ref<Rectangle> vr;
	for(int i=0;i<16;++i)
		for (int j = 0; j < 16; ++j) {
			vr.push_back(new Rectangle{ Point{i * 20,j * 20},20,20 });
			vr[vr.size() - 1].set_fill_color(Color{ i * 16 + j });
			win.attach(vr[vr.size() - 1]);
		}

	Marked_polyline mpl{ "abcd" };
	mpl.add(Point{ 100,100 });
	mpl.add(Point{ 150,200 });
	mpl.add(Point{ 250,250 });
	mpl.add(Point{ 300,200 });
	win.attach(mpl);

	Marks pp { "ab" };
	
	pp.add(Point{ 400,400 });
	pp.add(Point{ 450,500 });
	pp.add(Point{ 550,550 });
	pp.add(Point{ 500,500 });
	win.attach(pp);

	Mark p{ {600,600},'x' };
	win.attach(p);
	//插入图片
	Image qjl{ Point{400,400},"qjl.jpg",Suffix::jpg};
	win.attach(qjl);


	win.wait_for_button();       // give control to the display engine
}



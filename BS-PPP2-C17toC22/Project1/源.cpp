
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

    Point leftup(100, 100);           // to become top left  corner of window
    Simple_window win(leftup, 700, 700, "project");    // make a simple window

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
    poly.set_style(Line_style(Line_style::dash,4));
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

    //image
    Image ii{ Point{100,50},"picture.jpg" };
    ii.set_mask(Point{ 500,500 }, 200, 150);
    ii.move(200, 200);
    win.attach(ii);

    //circle & ellipse
    Circle c{ Point{100,200},50 };
    Ellipse e{ Point{100,200},75,25 };
    e.set_color(Color::dark_red);
    Mark m{ Point{100,200},'x' };
    win.attach(c);
    win.attach(e);
    win.attach(m);

    //text by output string stream
    ostringstream oss;
    oss << "screen size:" << x_max() << "*" << y_max() << ";window_size:" << win.x_max() << "*" << win.y_max();
    Text sizes{ Point{100,20},oss.str() };
    win.attach(sizes);

    win.set_label("canvas");

    win.wait_for_button();       // give control to the display engine
}

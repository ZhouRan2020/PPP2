
//
// This is example code from Chapter 12.3 "A first example" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include "Simple_window.h"    // get access to our window library
#include "Graph.h"            // get access to our graphics library facilities

//------------------------------------------------------------------------------

int main()
{
//    using namespace Graph_lib;   // our graphics facilities are in Graph_lib

    gl::Point leftup(100, 100);           // to become top left  corner of window
    Simple_window win(leftup, 800, 800, "project");    // make a simple window
    win.wait_for_button();       // give control to the display engine

    //x axis
    gl::Axis xa{ gl::Axis::x,gl::Point{20,300},280,10,"x axis" };
    win.attach(xa);
    win.wait_for_button();       // give control to the display engine

    //y axis
    gl::Axis ya{ gl::Axis::y,gl::Point{20,300},280,10,"y axis" };
    ya.set_color(gl::Color::cyan);
    ya.label.set_color(gl::Color::dark_red);
    win.attach(ya);
    win.wait_for_button();       // give control to the display engine

    //sin function
    gl::Function sine{ sin,0,100,gl::Point{20,150},1000,50,50 };
    sine.set_color(gl::Color::blue);
    win.attach(sine);
    win.wait_for_button();       // give control to the display engine

    //polygon
    gl::Polygon poly;
    poly.add(gl::Point{ 300,200 });
    poly.add(gl::Point{ 350,100 });
    poly.add(gl::Point{ 400,200 });
    poly.set_color(gl::Color::red);
    poly.set_style(gl::Line_style(gl::Line_style::dash,4));
    win.attach(poly);
    win.wait_for_button();       // give control to the display engine

    //rectangle
    gl::Rectangle r{ gl::Point{200,300},100,50 };
    r.set_fill_color(gl::Color::yellow);
    win.attach(r);
    win.wait_for_button();       // give control to the display engine

    //closed polyline
    gl::Closed_polyline poly_rect;
    poly_rect.add(gl::Point{ 100,50 });
    poly_rect.add(gl::Point{ 200,50 });
    poly_rect.add(gl::Point{ 200,100 });
    poly_rect.add(gl::Point{ 100,100 });
    poly_rect.add(gl::Point{ 50,75 });
    poly_rect.set_style(gl::Line_style(gl::Line_style::dash, 2));
    poly_rect.set_fill_color(gl::Color::green);
    win.attach(poly_rect);
    win.wait_for_button();       // give control to the display engine

    //text
    gl::Text t{ gl::Point{150,150},"Hello, graphical world!" };
    t.set_font(gl::Font::times_bold);
    t.set_fill_color(20);
    win.attach(t);
    win.wait_for_button();       // give control to the display engine

    //image
    gl::Image ii{ gl::Point{400,400},"resource/zr.jpg",gl::Suffix::jpg};
    ii.set_mask(gl::Point{ 500,500 }, 200, 150);
    ii.move(200, 200);
    win.attach(ii);
    win.wait_for_button();       // give control to the display engine

    //circle & ellipse
    gl::Circle c{ gl::Point{100,200},50 };
    gl::Ellipse e{ gl::Point{100,200},75,25 };
    e.set_color(gl::Color::dark_red);
    gl::Mark m{ gl::Point{100,200},'x' };
    win.attach(c);
    win.wait_for_button();       // give control to the display engine
    win.attach(e);
    win.wait_for_button();       // give control to the display engine
    win.attach(m);
    win.wait_for_button();       // give control to the display engine

    //text by output string stream
    std::ostringstream oss;
    oss << "screen size:" << gl::x_max() << "*" << gl::y_max() << ";window_size:" << win.x_max() << "*" << win.y_max();
    gl::Text sizes{ gl::Point{100,20},oss.str() };
    win.attach(sizes);
    win.wait_for_button();       // give control to the display engine

    win.set_label("canvas");

    win.wait_for_button();       // give control to the display engine
}

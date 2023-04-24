#include "FL/Enumerations.H"
#include "GUI.h"
#include "Graph.h"
#include "Point.h"
#include "Window.h"
#include <sstream>
struct Lines_window : gl::Window {
  Lines_window(gl::Point xy, int w, int h, const std::string &title)
      : gl::Window(xy, w, h, title),
        next_button(
            gl::Point{x_max() - 150, 0}, 70, 20, "next point",
            [](Address, Address pw) { reference_to<Lines_window>(pw).next(); }),
        quit_button(
            gl::Point{x_max() - 70, 0}, 70, 20, "quit",
            [](Address, Address pw) { reference_to<Lines_window>(pw).quit(); }),
        next_x(gl::Point{x_max() - 310, 0}, 50, 20, "next x:"),
        next_y(gl::Point{x_max() - 210, 0}, 50, 20, "next y:"),
        xy_out{gl::Point{100, 0}, 100, 20, "current(x,y):"},
        color_menu{gl::Point{x_max() - 70, 40}, 70, 20, gl::Menu::vertical,
                   "color"},
        menu_button{gl::Point{x_max() - 80, 30}, 80, 30, "color menu",
                    [](Address, Address pw) {
                      reference_to<Lines_window>(pw).menu_pressed();
                    }},
        lines{} {
    attach(next_button);
    attach(quit_button);
    attach(next_x);
    attach(next_y);
    attach(xy_out);
    color_menu.attach(
        new gl::Button{gl::Point{0, 0}, 0, 0, "red", [](Address, Address pw) {
                         reference_to<Lines_window>(pw).red_pressed();
                       }});
    color_menu.attach(
        new gl::Button{gl::Point{0, 0}, 0, 0, "blue", [](Address, Address pw) {
                         reference_to<Lines_window>(pw).blue_pressed();
                       }});
    color_menu.attach(
        new gl::Button{gl::Point{0, 0}, 0, 0, "black", [](Address, Address pw) {
                         reference_to<Lines_window>(pw).black_pressed();
                       }});
    attach(color_menu);
    attach(menu_button);
    attach(lines);
    hide_menu();
  }

private:
  gl::Button next_button;
  gl::Button quit_button;
  gl::In_box next_x;
  gl::In_box next_y;
  gl::Out_box xy_out;
  gl::Menu color_menu;
  gl::Button menu_button;
  gl::Open_polyline lines;

  void next() {
    int x = next_x.get_int();
    int y = next_y.get_int();
    lines.add(gl::Point{x, y});

    std::ostringstream ss;
    ss << '(' << x << ',' << y << ')';
    xy_out.put(ss.str());
    redraw();
  }
  void quit() { hide(); }

  void red_pressed() {
    change(gl::Color::red);
    hide_menu();
  }
  void blue_pressed() {
    change(gl::Color::blue);
    hide_menu();
  }
  void black_pressed() {
    change(gl::Color::black);
    hide_menu();
  }
  void menu_pressed() {
    menu_button.hide();
    color_menu.show();
  }

  void hide_menu() {
    color_menu.hide();
    menu_button.show();
  }
  void change(gl::Color c) { lines.set_color(c); }
};
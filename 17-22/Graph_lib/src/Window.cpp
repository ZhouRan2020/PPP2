#include "Window.h"
#include "GUI.h"
#include "Graph.h"

// namespace gl {

gl::Window::Window(int ww, int hh, const std::string &title)
    : Fl_Window(ww, hh, title.c_str()), w(ww), h(hh) {
  init();
}

gl::Window::Window(Point xy, int ww, int hh, const std::string &title)
    : Fl_Window(xy.x, xy.y, ww, hh, title.c_str()), w(ww), h(hh) {
  init();
}

//----------------------------------------------------

//----------------------------------------------------------------
// hint: Window:Fl_Window:Fl_Group:Fl_Widget
void gl::Window::attach(Widget &w) {
  begin();         // FTLK: begin attaching new Fl_Wigets to this window
  w.attach(*this); // Let the Widget creates its own Fl_*
  end();           // FTLK: stop attaching new Fl_Wigets to this window
}

// call Widget's hide(), is Fl_Widget's hide()
void gl::Window::detach(Widget &b) { b.hide(); }

// push &s to the back of array shapes
void gl::Window::attach(Shape &s) { shapes.push_back(&s); }

// erase &s from array shapes (which is the closest to the back i.e. last
// attached will first be removed)
void gl::Window::detach(Shape &s) {
  for (unsigned int i = shapes.size(); 0 < i; --i)
    if (shapes[i - 1] == &s)
      shapes.erase(shapes.begin() + (i - 1));
}
//--------------------------------------------------------------------
// put &p at the back of array shapes
void gl::Window::put_on_top(Shape &p) {
  for (int i = 0; i < shapes.size(); ++i) {
    if (&p == shapes[i]) {
      for (++i; i < shapes.size(); ++i)
        shapes[i - 1] = shapes[i];
      shapes[shapes.size() - 1] = &p;
      return;
    }
  }
}
//---------------------------------------------------------------------
void gl::Window::draw() {
  Fl_Window::draw();
  for (unsigned int i = 0; i < shapes.size(); ++i)
    shapes[i]->draw();
}
//----------------------------------------------------------------------
void gl::Window::init() {
  resizable(this);
  show();
}
//--------------------------------------------------------------------------
int gl::gui_main() { return Fl::run(); }

//} // namespace gl

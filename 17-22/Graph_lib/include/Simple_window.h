#include "GUI.h"	// for Simple_window only (doesn't really belong in Window.h)
#include "Window.h"

// Simple_window is basic scaffolding for ultra-simple interaction with graphics
// it provides one window with one "next" button for ultra-simple animation
struct Simple_window : gl::Window {
	Simple_window(gl::Point xy, int w, int h, const std::string& title )
	: Window(xy,w,h,title),
	  button_pushed(false),
	  next_button(gl::Point(x_max()-70,0), 70, 20, "Next", cb_next) 
	  { attach(next_button); }
	
	void wait_for_button()
	// modified event loop
	// handle all events (as per default), but quit when button_pushed becomes true
	// this allows graphics without control inversion
	{
		while (!button_pushed) Fl::wait();
		button_pushed = false;
		Fl::redraw();
	}

	gl::Button next_button;
private:
	bool button_pushed;	
	static void cb_next(gl::Address, gl::Address addr) // callback for next_button
	//	{ reference_to<Simple_window>(addr).next(); }
	{
		static_cast<Simple_window*>(addr)->next();
	}
	void next() { button_pushed = true; }
};
//}//gl
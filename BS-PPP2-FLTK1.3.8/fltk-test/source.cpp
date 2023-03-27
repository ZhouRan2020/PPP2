#include <FL/Fl.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Window.H>

int main() {
	Fl_Window window(200, 200, "wt");
	Fl_Box box(0, 0, 200, 200, "hw");
	window.show();
	return Fl::run();
}


